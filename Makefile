program : src/main.cpp | bin
	g++ src/main.cpp -o bin/program
	bin/program

bin : 
	mkdir bin
