main.exe: main.o simple_iteration.o
	g++ main.o simple_iteration.o -o main.exe

main.o: simple_iteration.cpp main.cpp
	g++ -c simple_iteration.cpp
	g++ -c main.cpp
clean:
	rm *.exe
	rm *.o
