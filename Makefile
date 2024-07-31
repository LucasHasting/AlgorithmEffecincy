all: program

program: testProject.o
	g++ testProject.o -o count_sort

testProject.o: testProject.cpp
	g++ -c testProject.cpp

clean:
	rm -rf *.o program
