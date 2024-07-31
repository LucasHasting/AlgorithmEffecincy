all: program

program: analysis_functions.o countSort.o testProject.o
	g++ analysis_functions.o countSort.o testProject.o -o count_sort

analysis_functions.o: analysis_functions.cpp
	g++ -c analysis_functions.cpp

countSort.o: countSort.cpp
	g++ -c countSort.cpp

testProject.o: testProject.cpp
	g++ -c testProject.cpp

clean:
	rm -rf *.o program
