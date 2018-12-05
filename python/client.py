from HelloWorld import HelloWorld

from thrift import Thrift
from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol

if __name__ == '__main__':
    try:
        transport = TSocket.TSocket('localhost', 9090)
        transport = TTransport.TBufferedTransport(transport)
        protocol = TBinaryProtocol.TBinaryProtocol(transport)
        client = HelloWorld.Client(protocol)
        transport.open()
        
        print('client - ping')
        print('server - ' + client.ping())
  
        print('client - say')
        msg = client.say('Hello!')
        print('server - ' + msg)

        transport.close()
    except Thrift.TException as ex:
        print(ex.message)
