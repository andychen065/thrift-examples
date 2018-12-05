package main

import (
    "fmt"
    "git.apache.org/thrift.git/lib/go/thrift"
    "HelloWorld"
)

func runServer(transportFactory thrift.TTransportFactory, 
	protocolFactory thrift.TProtocolFactory, addr string) error {
	var err error
	transport, err := thrift.NewTServerSocket(addr)
	if err != nil {
		fmt.Println(err)
	}
	fmt.Printf("%T\n", transport)
	handler := NewHelloWorldHandler()
	processor := HelloWorld.NewHelloWorldProcessor(handler)
	server := thrift.NewTSimpleServer4(processor, transport, transportFactory, protocolFactory)
	fmt.Println("Starting thrift server in go...")
	return server.Serve()
}

func main() {
	transportFactory := thrift.NewTTransportFactory()
	protocolFactory := thrift.NewTBinaryProtocolFactoryDefault()
	transportFactory = thrift.NewTBufferedTransportFactory(8192)
	runServer(transportFactory, protocolFactory, "localhost:9090")
}
