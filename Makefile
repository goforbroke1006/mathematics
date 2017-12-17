.PHONY: all test clean build

all: build run

clean:
	rm -f ./build/*

build:
	mkdir ./build/ || true
	g++ -std=c++11 -o ./build/mathematics main.cpp

run:
	./build/mathematics

test: clean
	mkdir ./build/ || true
	g++ -std=c++11 -o ./build/tests_parser_test tests/parser-test.cpp && (./build/tests_parser_test || true)
