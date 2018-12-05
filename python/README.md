Running
=======

First, compile `HelloWorld.thrift`.

```bash
$ thrift -gen py -out . HelloWorld.thrift
```

After the compilation, the project structure will be as follows.

```bash
$ tree
.
├── HelloWorld
│   ├── HelloWorld-remote
│   ├── HelloWorld.py
│   ├── __init__.py
│   ├── constants.py
│   └── ttypes.py
├── HelloWorld.thrift
├── README.md
├── __init__.py
├── client.py
└── server.py

1 directory, 10 files
```
Now, start the server.

```bash
$ python server.py
```

You will see the following output.

```bash
Starting thrift server in python...
```

Then, under the same path but from another terminal, start the client.

```bash
$ python client.py
```

You will see the following output.

```bash
client - ping
server - pong
client - say
server - Received: Hello!
```

Now if you go back to the server window, you will see the following output.

```bash
Starting thrift server in python...
Received: Hello!
```

You can use `Ctrl+C` to stop the server.
