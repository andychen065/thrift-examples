# thrift-examples

## Installation

All the examples are tested in macOS Mojave 10.14.1. Thrift is installed using the following command.

```bash
brew install thrift
```

According to [Homebrew](https://formulae.brew.sh/formula/thrift), you may add `--with-java` and `--with-python@2` to install the modules for Java and Python respectively. However, both did **not** work for me. So besides the above command, I downloaded the source codes from [Apache](http://www.apache.org/dyn/closer.cgi?path=/thrift/0.11.0/thrift-0.11.0.tar.gz) and compiled these modules manually. All the following commands should be run from the root directory of the source codes of Thrift.

## Java Modules

```bash
cd lib/java # you will see a `build.xml`
ant # this will generate a folder `build`; run `brew install ant` first if you don't have it
cd build
sudo cp *.jar /Library/Java/Extensions
```

## Python Modules

```bash
cd lib/py
python setup.py install --user
```

## Go Modules

The supposed way to install the Thrift module for Go is as follows.

```bash
go get git.apache.org/thrigt.git/lib/go/thrift
```

This will create a `git.apache.org/thrift.git` in `$HOME/go/src`. However, it did not work for me due to version mismatch and generated the following error.

```bash
# HelloWorld
../../../go/src/HelloWorld/HelloWorld.go:154:14: not enough arguments in call to oprot.Flush
	have ()
	want (context.Context)
../../../go/src/HelloWorld/HelloWorld.go:171:16: not enough arguments in call to oprot.Flush
	have ()
	want (context.Context)
../../../go/src/HelloWorld/HelloWorld.go:184:16: not enough arguments in call to oprot.Flush
	have ()
	want (context.Context)
../../../go/src/HelloWorld/HelloWorld.go:198:24: not enough arguments in call to oprot.Flush
	have ()
	want (context.Context)
../../../go/src/HelloWorld/HelloWorld.go:219:16: not enough arguments in call to oprot.Flush
	have ()
	want (context.Context)
../../../go/src/HelloWorld/HelloWorld.go:232:16: not enough arguments in call to oprot.Flush
	have ()
	want (context.Context)
../../../go/src/HelloWorld/HelloWorld.go:246:24: not enough arguments in call to oprot.Flush
	have ()
	want (context.Context)
../../../go/src/HelloWorld/HelloWorld.go:267:16: not enough arguments in call to oprot.Flush
	have ()
	want (context.Context)
../../../go/src/HelloWorld/HelloWorld.go:280:16: not enough arguments in call to oprot.Flush
	have ()
	want (context.Context)
../../../go/src/HelloWorld/HelloWorld.go:294:24: not enough arguments in call to oprot.Flush
	have ()
	want (context.Context)
../../../go/src/HelloWorld/HelloWorld.go:294:24: too many errors
```

So I directly copied the version of Thrift that I installed using `brew install thrift`. You can find out the version installed by Homebrew in [`homebrew-core`](https://github.com/Homebrew/homebrew-core/blob/master/Formula/thrift.rb). In my case, it is [https://www.apache.org/dyn/closer.cgi?path=/thrift/0.11.0/thrift-0.11.0.tar.gz](https://www.apache.org/dyn/closer.cgi?path=/thrift/0.11.0/thrift-0.11.0.tar.gz). In this page, you can download the Thrift using the link [http://mirrors.hust.edu.cn/apache/thrift/0.11.0/thrift-0.11.0.tar.gz](http://mirrors.hust.edu.cn/apache/thrift/0.11.0/thrift-0.11.0.tar.gz). After downloading, untar it and move all the files to `$HOME/go/src/git.apache.org/thrift.git`.