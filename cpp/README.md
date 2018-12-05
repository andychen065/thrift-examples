Running
=======

This example is taken from the [tutorial](https://github.com/apache/thrift/tree/master/tutorial/cpp).

First, compile `tutorial.thrift`. Since it includes another `shared.thrift`, we need to specify `-r`.

```bash
$ thrift -r -gen cpp tutorial.thrift
```

After the compilation, the project structure will be as follows.

```bash
$ tree
.
├── Client.cpp
├── README.md
├── Server.cpp
├── gen-cpp
│   ├── Calculator.cpp
│   ├── Calculator.h
│   ├── Calculator_server.skeleton.cpp
│   ├── SharedService.cpp
│   ├── SharedService.h
│   ├── SharedService_server.skeleton.cpp
│   ├── shared_constants.cpp
│   ├── shared_constants.h
│   ├── shared_types.cpp
│   ├── shared_types.h
│   ├── tutorial_constants.cpp
│   ├── tutorial_constants.h
│   ├── tutorial_types.cpp
│   └── tutorial_types.h
├── shared.thrift
└── tutorial.thrift

1 directory, 19 files
```

If you encounter the error `'boost/tr1/functional.hpp' file not found`, this is because the newer versions of `boost` have removed `boost/tr1`. You may download an older version like [1.60.0](http://sourceforge.net/projects/boost/files/boost/1.60.0/) and copy `boost/tr1` to `/usr/local/opt/boost/include/boost`.

Now, compile and start the server.

```bash
$ g++ -std=c++11 -stdlib=libc++ -DHAVE_INTTYPES_H -DHAVE_NETINET_IN_H -Wall -I/usr/local/include/thrift gen-cpp/Calculator.cpp gen-cpp/SharedService.cpp gen-cpp/shared_constants.cpp gen-cpp/shared_types.cpp gen-cpp/tutorial_constants.cpp gen-cpp/tutorial_types.cpp Server.cpp -L/usr/local/lib -lthrift -o Server
$ ./Server
```

You will see the following output.

```bash
Starting thrift server in cpp...
```

Then, under the same path but from another terminal, compile and start the client.

```bash
g++ -std=c++11 -stdlib=libc++ -DHAVE_INTTYPES_H -DHAVE_NETINET_IN_H -Wall -I/usr/local/include/thrift gen-cpp/Calculator.cpp gen-cpp/SharedService.cpp gen-cpp/shared_constants.cpp gen-cpp/shared_types.cpp gen-cpp/tutorial_constants.cpp gen-cpp/tutorial_types.cpp Client.cpp -L/usr/local/lib -lthrift -o Client
$ ./Client
```

You will see the following output.

```bash
ping()
1 + 1 = 2
InvalidOperation: Cannot divide by 0
15 - 10 = 5
Received log: SharedStruct(key=1, value=5)
```

Now if you go back to the server window, you will see the following output.

```bash
Incoming connection
	SocketInfo: <Host: ::1 Port: 59032>
	PeerHost: localhost
	PeerAddress: ::1
	PeerPort: 59032
ping()
add(1, 1)
calculate(1, Work(num1=1, num2=0, op=DIVIDE, comment=<null>))
calculate(1, Work(num1=15, num2=10, op=SUBTRACT, comment=<null>))
getStruct(1)
```

You can use `Ctrl+C` to stop the server.
