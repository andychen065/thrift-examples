#include <thrift/concurrency/ThreadManager.h>
#include <thrift/concurrency/PlatformThreadFactory.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/server/TThreadPoolServer.h>
#include <thrift/server/TThreadedServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include <thrift/TToString.h>
#include <thrift/stdcxx.h>

#include <iostream>
#include <stdexcept>
#include <sstream>

#include "gen-cpp/Calculator.h"

using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::concurrency;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace apache::thrift::server;

using namespace tutorial;
using namespace shared;

class CalculatorHandler : public CalculatorIf {
public:
    CalculatorHandler() {}

    void ping() { cout << "ping()" << endl; }

    int32_t add(const int32_t n1, const int32_t n2) {
        cout << "add(" << n1 << ", " << n2 << ")" << endl;
        return n1 + n2;
    }

    int32_t calculate(const int32_t logid, const Work& work) {
        cout << "calculate(" << logid << ", " << work << ")" << endl;
        int32_t val;

        switch (work.op) {
        case Operation::ADD:
            val = work.num1 + work.num2;
            break;
        case Operation::SUBTRACT:
            val = work.num1 - work.num2;
            break;
        case Operation::MULTIPLY:
            val = work.num1 * work.num2;
            break;
        case Operation::DIVIDE:
            if (work.num2 == 0) {
                InvalidOperation io;
                io.whatOp = work.op;
                io.why = "Cannot divide by 0";
                throw io;
            }
            val = work.num1 / work.num2;
            break;
        default:
            InvalidOperation io;
            io.whatOp = work.op;
            io.why = "Invalid Operation";
            throw io;
        }

        SharedStruct ss;
        ss.key = logid;
        ss.value = to_string(val);

        log[logid] = ss;

        return val;
    }

    void getStruct(SharedStruct& ret, const int32_t logid) {
        cout << "getStruct(" << logid << ")" << endl;
        ret = log[logid];
    }

    void zip() { cout << "zip()" << endl; }

protected:
    map<int32_t, SharedStruct> log;
};

class CalculatorCloneFactory : virtual public CalculatorIfFactory {
public:
    virtual ~CalculatorCloneFactory() {}

    virtual CalculatorIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) {
        stdcxx::shared_ptr<TSocket> sock = stdcxx::dynamic_pointer_cast<TSocket>(connInfo.transport);
        cout << "Incoming connection\n";
        cout << "\tSocketInfo: "  << sock->getSocketInfo()  << "\n";
        cout << "\tPeerHost: "    << sock->getPeerHost()    << "\n";
        cout << "\tPeerAddress: " << sock->getPeerAddress() << "\n";
        cout << "\tPeerPort: "    << sock->getPeerPort()    << "\n";
        return new CalculatorHandler;
    }
    
    virtual void releaseHandler( ::shared::SharedServiceIf* handler) {
        delete handler;
    }
};

int main() {
    TThreadedServer server(
        stdcxx::make_shared<CalculatorProcessorFactory>(stdcxx::make_shared<CalculatorCloneFactory>()),
        stdcxx::make_shared<TServerSocket>(9090),
        stdcxx::make_shared<TBufferedTransportFactory>(),
        stdcxx::make_shared<TBinaryProtocolFactory>());

    cout << "Starting thrift server in cpp..." << endl;
    server.serve();
    cout << "Done." << endl;
    return 0;
}
