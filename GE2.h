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
//insertion sort 
void insertionsort(int arr[], int left, int right);

