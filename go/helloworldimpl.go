package main

import "context"

type HelloWorldHandler struct {
}

func NewHelloWorldHandler() *HelloWorldHandler {
	return &HelloWorldHandler{}
}

func (h *HelloWorldHandler) HelloString(ctx context.Context, para string) (r string, e error) {
	return "Hello, world", nil
}

func (h *HelloWorldHandler) HelloInt(ctx context.Context, para int32) (r int32, e error) {
	return para, nil
}

func (h *HelloWorldHandler) HelloBoolean(ctx context.Context, para bool) (r bool, e error) {
    return para, nil
}

func (h *HelloWorldHandler) HelloVoid(ctx context.Context) (e error) {
	return nil
}

func (h *HelloWorldHandler) HelloNull(ctx context.Context) (r string, e error) {
	return "Hello, null", nil
}
