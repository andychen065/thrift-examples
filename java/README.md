Dependencies
============

To run the Java example, you still need two more dependencies.

* [`org.apache.commons.lang3`](https://commons.apache.org/proper/commons-lang/download_lang.cgi)
* [`org.slf4j`](https://www.slf4j.org/download.html)

As a simple solution, you can download them from the links above and copy the `.jar` files to `/Library/Java/Extentions`. You may also use [Maven](https://maven.apache.org/) or [Gradle](https://gradle.org/) to manage them.

Running
=======

First, compile `HelloWorld.thrift`.

```bash
$ thrift -gen java -out . HelloWorld.thrift
```

After the compilation, the project structure will be as follows.

```bash
$tree
.
├── HelloWorld.thrift
├── HelloWorldClient.java
├── HelloWorldImpl.java
├── HelloWorldServer.java
├── README.md
└── com
    └── jianchao
        └── thrift
            ├── HelloWorld.java
            ├── Request.java
            ├── RequestException.java
            └── RequestType.java

3 directories, 9 files
```

Now, compile the java classes.

```bash
$ javac -cp . -d . *.java
```

A lot of `.class` files will be added to `com/jianchao/thrift`.

```bash
$ tree.
├── HelloWorld.thrift
├── HelloWorldClient.java
├── HelloWorldImpl.java
├── HelloWorldServer.java
├── README.md
└── com
    └── jianchao
        └── thrift
            ├── HelloWorld$1.class
            ├── HelloWorld$AsyncClient$Factory.class
            ├── HelloWorld$AsyncClient$doAction_call.class
            ├── HelloWorld$AsyncClient.class
            ├── HelloWorld$AsyncIface.class
            ├── HelloWorld$AsyncProcessor$doAction$1.class
            ├── HelloWorld$AsyncProcessor$doAction.class
            ├── HelloWorld$AsyncProcessor.class
            ├── HelloWorld$Client$Factory.class
            ├── HelloWorld$Client.class
            ├── HelloWorld$Iface.class
            ├── HelloWorld$Processor$doAction.class
            ├── HelloWorld$Processor.class
            ├── HelloWorld$doAction_args$_Fields.class
            ├── HelloWorld$doAction_args$doAction_argsStandardScheme.class
            ├── HelloWorld$doAction_args$doAction_argsStandardSchemeFactory.class
            ├── HelloWorld$doAction_args$doAction_argsTupleScheme.class
            ├── HelloWorld$doAction_args$doAction_argsTupleSchemeFactory.class
            ├── HelloWorld$doAction_args.class
            ├── HelloWorld$doAction_result$_Fields.class
            ├── HelloWorld$doAction_result$doAction_resultStandardScheme.class
            ├── HelloWorld$doAction_result$doAction_resultStandardSchemeFactory.class
            ├── HelloWorld$doAction_result$doAction_resultTupleScheme.class
            ├── HelloWorld$doAction_result$doAction_resultTupleSchemeFactory.class
            ├── HelloWorld$doAction_result.class
            ├── HelloWorld.class
            ├── HelloWorld.java
            ├── HelloWorldClient.class
            ├── HelloWorldImpl.class
            ├── HelloWorldServer.class
            ├── Request$1.class
            ├── Request$RequestStandardScheme.class
            ├── Request$RequestStandardSchemeFactory.class
            ├── Request$RequestTupleScheme.class
            ├── Request$RequestTupleSchemeFactory.class
            ├── Request$_Fields.class
            ├── Request.class
            ├── Request.java
            ├── RequestException$1.class
            ├── RequestException$RequestExceptionStandardScheme.class
            ├── RequestException$RequestExceptionStandardSchemeFactory.class
            ├── RequestException$RequestExceptionTupleScheme.class
            ├── RequestException$RequestExceptionTupleSchemeFactory.class
            ├── RequestException$_Fields.class
            ├── RequestException.class
            ├── RequestException.java
            ├── RequestType.class
            └── RequestType.java

3 directories, 53 files
```

Now, start the server.

```bash
cd com/jianchao/thrift
java -cp ../../.. com.jianchao.thrift.HelloWorldServer
```

You will see the following output.

```bash
SLF4J: Class path contains multiple SLF4J bindings.
SLF4J: Found binding in [jar:file:/Library/Java/Extensions/slf4j-simple-1.7.25.jar!/org/slf4j/impl/StaticLoggerBinder.class]
SLF4J: Found binding in [jar:file:/Library/Java/Extensions/slf4j-log4j12-1.7.25.jar!/org/slf4j/impl/StaticLoggerBinder.class]
SLF4J: Found binding in [jar:file:/Library/Java/Extensions/slf4j-jdk14-1.7.25.jar!/org/slf4j/impl/StaticLoggerBinder.class]
SLF4J: Found binding in [jar:file:/Library/Java/Extensions/slf4j-jcl-1.7.25.jar!/org/slf4j/impl/StaticLoggerBinder.class]
SLF4J: Found binding in [jar:file:/Library/Java/Extensions/slf4j-android-1.7.25.jar!/org/slf4j/impl/StaticLoggerBinder.class]
SLF4J: Found binding in [jar:file:/Library/Java/Extensions/slf4j-nop-1.7.25.jar!/org/slf4j/impl/StaticLoggerBinder.class]
SLF4J: See http://www.slf4j.org/codes.html#multiple_bindings for an explanation.
SLF4J: Actual binding is of type [org.slf4j.impl.SimpleLoggerFactory]
Starting thrift server in java...
```

Then, under the same path but from another terminal, start the client.

```bash
$ java -cp ../../.. com.jianchao.thrift.HelloWorldClient
```

You will see the following output (note the last two lines).

```bash
SLF4J: Class path contains multiple SLF4J bindings.
SLF4J: Found binding in [jar:file:/Library/Java/Extensions/slf4j-simple-1.7.25.jar!/org/slf4j/impl/StaticLoggerBinder.class]
SLF4J: Found binding in [jar:file:/Library/Java/Extensions/slf4j-log4j12-1.7.25.jar!/org/slf4j/impl/StaticLoggerBinder.class]
SLF4J: Found binding in [jar:file:/Library/Java/Extensions/slf4j-jdk14-1.7.25.jar!/org/slf4j/impl/StaticLoggerBinder.class]
SLF4J: Found binding in [jar:file:/Library/Java/Extensions/slf4j-jcl-1.7.25.jar!/org/slf4j/impl/StaticLoggerBinder.class]
SLF4J: Found binding in [jar:file:/Library/Java/Extensions/slf4j-android-1.7.25.jar!/org/slf4j/impl/StaticLoggerBinder.class]
SLF4J: Found binding in [jar:file:/Library/Java/Extensions/slf4j-nop-1.7.25.jar!/org/slf4j/impl/StaticLoggerBinder.class]
SLF4J: See http://www.slf4j.org/codes.html#multiple_bindings for an explanation.
SLF4J: Actual binding is of type [org.slf4j.impl.SimpleLoggerFactory]
Hello, Jianchao, welcome!
Hello, Jianchao, now it's Dec 4, 2018 7:42:19 PM
```

Now if you go back to the server window, you will see two new lines in the output.

```bash
Get request: Request(type:SAY_HELLO, name:Jianchao, age:27)
Get request: Request(type:QUERY_TIME, name:Jianchao, age:27)
```

You can use `Ctrl+C` to stop the server.
