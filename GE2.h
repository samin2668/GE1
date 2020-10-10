#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <array>
#include <chrono>
using namespace std;

//split array
void mergesort(int arr[], int srt[], int left, int right, int size);
//merge array
void merge(int arr[], int srt[], int leftpos, int rightpos, int end, int size);
/* The main function that implements QuickSort  
arr[] --> Array to be sorted,  
low --> Starting index,  
high --> Ending index */
void quickSort(int arr[], int low, int high);
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

