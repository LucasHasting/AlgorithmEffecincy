#include <iostream>
#include <ctime>
#include <time.h>
#include "countSort1.cpp"
using namespace std;

template <class T>
void Random(T *array, int size, int max){
    srand(time(0));

    for(int i = 0; i < size; i++){
            T random = rand() % max;
            array[i] = random;
    }
}

template <class T>
void Asscending(T *array, int size){
    for(int i = 0; i < size; i++){
            array[i] = i + 1;
    }
}

template <class T>
void Decending(T *array, int size){
    for(int i = size - 1, j = 0; j < size; i--, j++){
            array[i] = j + 1;
    }
}

template <class T>
double test(T *array, int size, int max, string type = "Random")
{
    clock_t t1, t2;
    if (type == "Random")
    	Random<T>(array, size, max);
    else if (type == "Asscending")
	Asscending<T>(array, size);
    else if (type == "Decending")
	Decending<T>(array, size);
    else
	return 0;
    t1 = clock();

    //test algorithm
    countSort<T>(array, size);

    t2 = clock();
    float diff (float(t2) - float(t1));
    return diff / CLOCKS_PER_SEC;
}

int main()
{
    //2147483647
    //1073741823
    //35791396 - highest working number
    //35750000
    
    int max = 35750000;
    int size = max;
    clock_t t1, t2, t3, t4, t5;
    t1 = clock(); 
    
    //int
    //size with size   
    for (int temp_size = size; temp_size > 0; temp_size -= 250000){
    int *arr = new int[temp_size];
    cout << test<int>(arr, temp_size, temp_size) << endl;
    cout << test<int>(arr, temp_size, 0, "Asscending") << endl;
    cout << test<int>(arr, temp_size, 0, "Decending") << endl;
    cout << "Size: " << temp_size << endl;
    cout << endl;

    delete [] arr;
    }

    t2 = clock();
    double diff = float(t2) - float(t1);
    cout << "Total Time (Seconds): " << (diff / CLOCKS_PER_SEC) << endl;
    cout << "Total Time (Minutes): " << ((diff / CLOCKS_PER_SEC) / 60) << endl << endl;
    
    //size with max   
    for (int temp_size = size, i = 0; temp_size > 0; temp_size -= 250000, i++){
    int *arr = new int[temp_size];
    cout << test<int>(arr, temp_size, max+i) << endl;
    cout << test<int>(arr, temp_size, 0, "Asscending") << endl;
    cout << test<int>(arr, temp_size, 0, "Decending") << endl;
    cout << "Size: " << temp_size << endl;
    cout << endl;

    delete [] arr;
    }

    t3 = clock();
    diff = float(t3) - float(t2);
    cout << "Total Time: " << (diff / CLOCKS_PER_SEC) << endl;
    cout << "Total Time (Minutes): " << ((diff / CLOCKS_PER_SEC) / 60) << endl << endl;
    
    //size with small max  
    max = 10;
    for (int temp_size = size, i = 0; temp_size > 0; temp_size -= 250000, i++){
    int *arr = new int[temp_size];
    cout << test<int>(arr, temp_size, max) << endl;
    cout << test<int>(arr, temp_size, 0, "Asscending") << endl;
    cout << test<int>(arr, temp_size, 0, "Decending") << endl;
    cout << "Size: " << temp_size << endl;
    cout << endl;

    delete [] arr;
    }

    t4 = clock();
    diff = float(t4) - float(t3);
    cout << "Total Time: " << (diff / CLOCKS_PER_SEC) << endl;
    cout << "Total Time (Minutes): " << ((diff / CLOCKS_PER_SEC) / 60) << endl << endl;
    
    t4 = clock();
    diff = float(t4) - float(t1);
    cout << "Total Overall Time: " << (diff / CLOCKS_PER_SEC) << endl;
    cout << "Total Time (Minutes): " << ((diff / CLOCKS_PER_SEC) / 60) << endl << endl;
    /*
    //double
    //size with size   
    for (int temp_size = size; temp_size > 0; temp_size--){
    double *arr = new double[temp_size];
    cout << test<double>(arr, temp_size, size) << endl;
    cout << test<double>(arr, temp_size, 0, "Asscending") << endl;
    cout << test<double>(arr, temp_size, 0, "Decending") << endl;
    cout << "Size: " << temp_size << endl;
    cout << endl;

    delete [] arr;
    }

    t4 = clock();
    float diff (float(t2) - float(t1));
    cout << "Total Time (Seconds): " << (diff / CLOCKS_PER_SEC) << endl;
    cout << "Total Time (Minutes): " << ((diff / CLOCKS_PER_SEC) / 60) << endl;
    cout << "Total Time (Hours): " << (((diff / CLOCKS_PER_SEC) / 60) / 60) << endl << endl;
    
    //size with max   
    for (int temp_size = size; temp_size > 0; temp_size--){
    double *arr = new double[temp_size];
    cout << test<double>(arr, temp_size, max) << endl;
    cout << test<double>(arr, temp_size, 0, "Asscending") << endl;
    cout << test<double>(arr, temp_size, 0, "Decending") << endl;
    cout << "Size: " << temp_size << endl;
    cout << endl;

    delete [] arr;
    }

    t5 = clock();
    diff = float(t2) - float(t1);
    cout << "Total Time: " << (diff / CLOCKS_PER_SEC) << endl;
    cout << "Total Time (Minutes): " << ((diff / CLOCKS_PER_SEC) / 60) << endl;
    cout << "Total Time (Hours): " << (((diff / CLOCKS_PER_SEC) / 60) / 60) << endl;
    */
}
