/*
Names: Lucas Hasting, Ethan Nix, Krutivas Pradhan
Course: CS 355
Assignment: Assignment 7
Date: 2/23/2023
Program Description: Test the countingSort function
File Name: analysis_functions.cpp
File Contribution: Lucas Hasting, Ethan Nix, Krutivas Pradhan
*/

/*
Function Name: dataWrite
Function Description: Appends the parameters to a file clalled data.csv
Incoming: test_type, size, max, time
Outgoing: None
Return: None
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
Function Name: Ascending
Function Description: Puts number in the array from 1-size in ascending order
Incoming: array, size
Outgoing: array
Return: None
Function Contribution: Lucas Hasting
*/
template <class T>
void Ascending(T *array, int size){
    for(int i = 0; i < size; i++){
            array[i] = i + 1;
    }
}

/*
Function Name: Descending
Function Description: Puts number in the array from 1-size in descending order
Incoming: array, size
Outgoing: array
Return: None
Function Contribution: Lucas Hasting
*/
template <class T>
void Descending(T *array, int size){
    for(int i = size - 1, j = 0; j < size; i--, j++){
            array[i] = j + 1;
    }
}

/*
Function Name: SemiRandom
Function Description: Puts numbers in the array in semi-random order
Incoming: array, size
Outgoing: array
Return: None
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
Function Name: Random
Function Description: Puts numbers in the array in random order
Incoming: array, size
Outgoing: array
Return: None
Function Contribution: Lucas Hasting
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
Function Name: test
Function Description: test the speed of the counting sort
Incoming: array, size, max, type
Outgoing: array
Return: diff / CLOCKS_PER_SEC
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
