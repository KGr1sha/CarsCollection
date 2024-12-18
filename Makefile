objects = car.o\
		  vintage.o\
		  super.o\
		  collection.o\
		  csvhandler.o


program : $(objects) src/main.cpp | bin
	g++ $(objects) src/main.cpp -o bin/program
	make clean
	bin/program

tests : $(objects) src/tests.cpp | bin
	g++ $(objects) src/tests.cpp -o bin/tests
	make clean
	bin/tests

bin : 
	mkdir bin

car.o : src/car.cpp
	g++ -c src/car.cpp -o car.o

vintage.o : src/vintage_car.cpp
	g++ -c src/vintage_car.cpp -o vintage.o

super.o : src/supercar.cpp
	g++ -c src/supercar.cpp -o super.o

collection.o : src/collection.cpp
	g++ -c src/collection.cpp -o collection.o

csvhandler.o : src/csvhandler.cpp
	g++ -c src/csvhandler.cpp -o csvhandler.o


clean :
	rm $(objects)
