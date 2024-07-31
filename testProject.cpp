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
