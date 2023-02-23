/*
Names: Lucas Hasting, Ethan Nix, Krutivas Pradhan
Course: CS 355
Assignment: Assignment 7
Date: 2/23/2023
Program Description: Test the countingSort function
File Name: testProject.cpp
File Contribution: Lucas Hasting, Ethan Nix, Krutivas Pradhan
*/

#include <iostream>
#include <ctime>
#include <time.h>
#include <fstream>
#include "countSort.cpp"
using namespace std;

/*
Function Name:
Function Description:
Incoming:
Outgoing:
Return:
Function Contribution: Krutivas Pradhan
*/
void dataWrite(string test_type, int size, int max, double time)
{
    ofstream outfile;
    outfile.open("data.csv", ios::app);
    outfile << test_type << "," << max << "," << size << "," << time;
    outfile << endl;
    outfile.close();
}

/*
Function Name:
Function Description:
Incoming:
Outgoing:
Return:
Function Contribution: Lucas Hasting
*/
template <class T>
void Ascending(T *array, int size){
    for(int i = 0; i < size; i++){
            array[i] = i + 1;
    }
}

/*
Function Name:
Function Description:
Incoming:
Outgoing:
Return:
Function Contribution: Lucas Hasting
*/
template <class T>
void Descending(T *array, int size){
    for(int i = size - 1, j = 0; j < size; i--, j++){
            array[i] = j + 1;
    }
}

/*
Function Name:
Function Description:
Incoming:
Outgoing:
Return:
Function Contribution: Ethan Nix
*/
template <class T>
void SemiRandom(T *array, int size){
    Ascending(array, size);
    for(int i = 0; i < size/2; i++){
	    T temp = array[i];
	    array[i] = array[size/2 + i];
	    array[size/2 + i] = temp;
    }
}

/*
Function Name:
Function Description:
Incoming:
Outgoing:
Return:
Function Contribution: Ethan Nix
*/
template <class T>
void Random(T *array, int size, int max){
    srand(time(0));

    for(int i = 0; i < size; i++){
            T random = rand() % max;
            array[i] = random;
    }
}

/*
Function Name:
Function Description:
Incoming:
Outgoing:
Return:
Function Contribution: Lucas Hasting
*/
template <class T>
double test(T *array, int size, int max, string type = "Random")
{
    //enter data into the array
    clock_t t1, t2;
    if (type == "Random")
    	Random<T>(array, size, max);
    else if (type == "Ascending")
        Ascending<T>(array, size);
    else if (type == "Descending")
        Descending<T>(array, size);
    else if (type == "Semi-Random")
        SemiRandom<T>(array, size);
    else
        return 0;
    t1 = clock();

    //test algorithm
    countSort<T>(array, size);

    t2 = clock();

    //time function
    float diff (float(t2) - float(t1));
    return diff / CLOCKS_PER_SEC;
}

/*
Driver Function
Function Contribution: Lucas Hasting, Ethan Nix, Krutivas Pradhan
*/
int main()
{
    ofstream outfile;
    outfile.open("data.csv");
    outfile << "test_type,max,size,time" << endl;
    outfile.close();
    int max = 150000000;
    int size = max;

    //tests the data and writes it to data.csv
    for (int temp_size = size, i = 0; temp_size > 0; temp_size -= 1500000, i++){
    int *arr = new int[temp_size];
    dataWrite("Random", temp_size, temp_size, test<int>(arr, temp_size, temp_size));
    dataWrite("Ascending", temp_size, temp_size, test<int>(arr, temp_size, 0, "Ascending"));
    dataWrite("Descending", temp_size, temp_size, test<int>(arr, temp_size, 0, "Descending"));
    dataWrite("Semi-Random", temp_size, temp_size, test<int>(arr, temp_size, 0, "Semi-Random"));
    dataWrite("Random-Max", temp_size, max+i*2, test<int>(arr, temp_size, max+i*2));
    dataWrite("Random-Min", temp_size, 10, test<int>(arr, temp_size, 10));

    //indicate an iteration has finished
    cout << ".";

    //delete array
    delete [] arr;
    }

    //indicate the testing is done
    cout << "Done" << endl;
    return 0;
}
