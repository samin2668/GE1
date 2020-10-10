#include "GE2.h"


void mergesort(int arr[], int srt[], int left, int right, int size)
{
    //get size
    int elements = right - left + 1;
    //check is array was split 
    if(left < right)
    {
        //check if there are more that 8 elements for 
        if(elements > 8)
        {
            int center = (left + right) / 2;
            mergesort(arr, srt, left, center, size);
            mergesort(arr, srt, center + 1, right, size);
            merge(arr, srt, left, center + 1, right, size);
        }
        //insertion sort if 8 elements or less
        else
        {
            insertionsort(arr, left, right);
        }
        
    }
}

void merge(int arr[], int srt[], int leftpos, int rightpos, int rightend, int size)
{
    int leftend = rightpos - 1;
    int tmppos = leftpos;
    int elements = rightend - leftpos + 1;
    //sort array into temp
    while(leftpos <= leftend && rightpos <= rightend)
    {
        if(arr[leftpos] <= arr[rightpos])
        {
            srt[tmppos++] = move(arr[leftpos++]);
        }
        else
        {
            srt[tmppos++] = move(arr[rightpos++]);
        }
        
    }  

    while(leftpos <= leftend)
    {
        srt[tmppos++] = move(arr[leftpos++]);
    }  

    while(rightpos <= rightend)
    {
        srt[tmppos++] = move(arr[rightpos++]);
    } 
    //copy over sorted temp array into original
    for(int i = 0; i < elements; ++i, --rightend)
    {
        arr[rightend] = move(srt[rightend]);
    }
}

void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
  
int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high]; // pivot  
    int i = (low - 1); // Index of smaller element  
  
    for (int j = low; j <= high - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (arr[j] < pivot)  
        {  
            i++; // increment index of smaller element  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  
  
/* The main function that implements QuickSort  
arr[] --> Array to be sorted,  
low --> Starting index,  
high --> Ending index */
void quickSort(int arr[], int low, int high)  
{   
    int size = high - low + 1;
    if(size == 1000)
        insertionsort(arr, low, high);
    else if (low < high)  
    {  
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partition(arr, low, high);  
  
        // Separately sort elements before  
        // partition and after partition  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}  

//insetion sort
void insertionsort(int arr[], int left, int right)
{
    for(int i = left + 1; i < right + 1; ++i)
    {
        double temp = move(arr[i]);
        int j;
        //pushback number until it is sorted into proper place
        for(j = i; j > left && temp < arr[j - 1]; --j)
            arr[j] = move(arr[j - 1]);
        arr[j] = move(temp);
    }
}