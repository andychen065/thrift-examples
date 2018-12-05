package main

import (
	"fmt"
	"context"
	"git.apache.org/thrift.git/lib/go/thrift"
	"HelloWorld"
)

func handleClient(client *HelloWorld.HelloWorldClient) error {
    var defaultCtx = context.Background()
	str, err := client.HelloString(defaultCtx, "")
	fmt.Println(str)
	fmt.Println("----------------")
	return err
}

func runClient(transportFactory thrift.TTransportFactory, protocolFactory thrift.TProtocolFactory, addr string) error {
	var transport thrift.TTransport
	var err error
	transport, err = thrift.NewTSocket(addr)
	if err != nil {
		fmt.Println("Error opening socket: ", err)
		return err
	}
	transport, err = transportFactory.GetTransport(transport)
	if err != nil {
	    fmt.Println("Error getting transport")
	    return err
	}
	defer transport.Close()
	if err := transport.Open(); err != nil {
		return err
	}
	fmt.Println(transport, protocolFactory)
	return handleClient(HelloWorld.NewHelloWorldClientFactory(transport, protocolFactory))
}

func main() {
	transportFactory := thrift.NewTTransportFactory()
	protocolFactory := thrift.NewTBinaryProtocolFactoryDefault()
	transportFactory = thrift.NewTBufferedTransportFactory(8192)
	runClient(transportFactory, protocolFactory, "localhost:9090")
}
