

all: env hello

dir:
	mkdir -p build

clean:
	rm -r build

env: dir
	g++ -o build/env.cgi src/env.cpp
	strip build/env.cgi

hello: dir
	g++ -o build/hello.cgi src/hello.cpp
	strip build/hello.cgi
