main: 
	g++ main.c -o output  -I../include -L../lib -lraylib -Wl,-rpath,../lib
	./output
