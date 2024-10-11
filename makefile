all: build	build/main # any thing here will run at command ished in cli make in the dir where makefile is 
build/main: build src/*.c include/*.h 
	gcc -o build/main -Include src/*.c -lSDL2
	./build/main


build:
	mkdir -p build 

clean :
	rm -rf build 
