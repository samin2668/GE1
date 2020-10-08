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