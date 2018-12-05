package com.jianchao.thrift;

import com.jianchao.thrift.HelloWorld.Processor;

import org.apache.thrift.server.TServer;
import org.apache.thrift.server.TServer.Args;
import org.apache.thrift.server.TSimpleServer;
import org.apache.thrift.transport.TServerSocket;

import java.net.ServerSocket;

public class HelloWorldServer {
	public static void main(String[] args) throws Exception {
		ServerSocket socket = new ServerSocket(9090);
		TServerSocket serverTransport = new TServerSocket(socket);
		Processor processor = new Processor(new HelloWorldImpl());
                TServer server = new TSimpleServer(new Args(serverTransport).processor(processor));
		System.out.println("Starting thrift server in java...");
		server.serve();
	}
}
