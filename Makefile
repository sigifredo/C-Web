

all: env get hello

dir:
	mkdir -p build

clean:
	rm -r build

env: dir
	g++ -o build/env.cgi src/env.cpp
	strip build/env.cgi

get: dir
	g++ -std=c++11 -o build/get.cgi src/get.cpp
	strip build/get.cgi

hello: dir
	g++ -o build/hello.cgi src/hello.cpp
	strip build/hello.cgi
