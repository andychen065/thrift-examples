Running
=======

First, compile `HelloWorld.thrift`.

```bash
$ thrift -gen go -out . HelloWorld.thrift
```

After the compilation, the project structure will be as follows.

```bash
$ tree
.
├── HelloWorld
│   ├── GoUnusedProtection__.go
│   ├── HelloWorld-consts.go
│   ├── HelloWorld.go
│   └── hello_world-remote
│       └── hello_world-remote.go
├── HelloWorld.thrift
├── README.md
├── helloworldclient.go
├── helloworldimpl.go
└── helloworldserver.go

2 directories, 9 files
```

The Go modules are supposed to be in `$HOME/go/src` by default. You may create a symbolic link to the generated Go module as follows.

```bash
cd HelloWorld
ln -s "$(pwd)" $HOME/go/src/HelloWorld
cd ..
```

The name of the folder in `$HOME/go/src` (`HelloWorld` in this case) will be the name of the Go module.

Now, start the server.

```bash
$ go run helloworldserver.go helloworldimpl.go
```

You will see the following output.

```bash
*thrift.TServerSocket
Starting thrift server in go...
```

Then, under the same path but from another terminal, start the client.

```bash
$ go run helloworldclient.go
```

You will see the following output.

```bash
&{{0xc0000723c0 0xc0000582c0} 0xc00007efc0} &{false true}
Hello, world
----------------
```

You can use `Ctrl+C` to stop the server.
