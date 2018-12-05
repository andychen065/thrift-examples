package com.jianchao.thrift;

import com.jianchao.thrift.HelloWorld;
import com.jianchao.thrift.Request;
import com.jianchao.thrift.RequestException;
import com.jianchao.thrift.RequestType;

import org.apache.commons.lang3.StringUtils;
import org.apache.thrift.TException;

import java.util.Date;

public class HelloWorldImpl implements HelloWorld.Iface {
    public String doAction(Request request) throws RequestException, TException {
        System.out.println("Get request: " + request);
        if (StringUtils.isBlank(request.getName()) || request.getType() == null) {
        	throw new RequestException();
        }
        String result = "Hello, " + request.getName();
        if (request.getType() == RequestType.SAY_HELLO) {
        	result += ", welcome!";
        } else {
        	result += ", now it's " + new Date().toLocaleString();
        }
        return result;
    }
}
