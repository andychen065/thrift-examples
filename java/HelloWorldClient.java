package com.jianchao.thrift;

import com.jianchao.thrift.HelloWorld.Client;
import com.jianchao.thrift.Request;
import com.jianchao.thrift.RequestType;

import org.apache.thrift.protocol.TBinaryProtocol;
import org.apache.thrift.protocol.TProtocol;
import org.apache.thrift.transport.TSocket;
import org.apache.thrift.transport.TTransport;

public class HelloWorldClient {
	public static void main(String[] args) throws Exception {
		TTransport transport = new TSocket("localhost", 9090);
		TProtocol protocol = new TBinaryProtocol(transport);

		Client client = new Client(protocol);
		transport.open();

		Request request = new Request().setType(RequestType.SAY_HELLO)
		                               .setName("Jianchao")
		                               .setAge(27);
		System.out.println(client.doAction(request));
		request.setType(RequestType.QUERY_TIME);
		System.out.println(client.doAction(request));

		transport.close();
	}
}
