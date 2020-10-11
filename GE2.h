#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <array>
#include <chrono>
#include <cstdlib>
using namespace std;
const int RUN = 32;

//split array
void mergesort(int arr[], int srt[], int left, int right, int size, int k);
//merge array
void merge(int arr[], int srt[], int leftpos, int rightpos, int end, int size);
/* The main function that implements QuickSort  
arr[] --> Array to be sorted,  
low --> Starting index,  
high --> Ending index */
void quickSort(int arr[], int low, int high, int k);
//swap function
void swap(int* a, int* b);
/* This function takes last element as pivot, places  
the pivot element at its correct position in sorted  
array, and places all smaller (smaller than pivot)  
to left of pivot and all greater elements to right  
of pivot */
int partition (int arr[], int low, int high);

//insertion sort 
void insertionsort(int arr[], int left, int right);

// A utility function to get maximum value in arr[]
int getMax(int arr[], int n);

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp);

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(int arr[], int n);

 // Iterative Timsort function to sort the
// array[0...n-1] (similar to merge sort)
void timSort(int arr[], int srt[], int n);

