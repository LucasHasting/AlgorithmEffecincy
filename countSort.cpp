//reference: https://www.tutorialspoint.com/cplusplus-program-to-implement-counting-sort

#include<iostream>
#include<algorithm>
using namespace std;

template <class T>
void display(T *array, int size) {
   for(int i = 0; i < size; i++)
      cout << array[i] << " ";
   cout << endl;
}

template <class T>
int getMax(T *array, int size) {
   T max = array[0];
   for(int i = 1; i<size; i++) {
      if(array[i] > max)
         max = array[i];
   }
   return max; //the max element from the array
}

template <class T>
void countSort(T *array, int size) {
   T *output = new T[size];
   T max = getMax<T>(array, size);
   T *count = new T[max+1];     //create count array (max+1 number of elements)

  // Initialize count array with all zeros.
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  // Store the count of each element
  for (int i = 0; i < size; i++) {
    count[int(array[i])]++;
  }

  // Store the cummulative count of each array
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  // Find the index of each element of the original array in count array, and
  // place the elements in output array
  for (int i = size - 1; i >= 0; i--) {
    output[int(count[int(array[i])] - 1)] = array[i];
    count[int(array[i])]--;
  }

  // Copy the sorted elements into original array
  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }

   //delete the arrays
   delete [] output;
   delete [] count;
}
