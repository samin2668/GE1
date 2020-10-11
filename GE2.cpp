#include "GE2.h"


void mergesort(int arr[], int srt[], int left, int right, int size, int k)
{
    //get size
    int elements = right - left + 1;
    //check is array was split 
    if(left < right)
    {
        //check if there are more that k elements for 
        if(elements > k)
        {
            int center = (left + right) / 2;
            mergesort(arr, srt, left, center, size, k);
            mergesort(arr, srt, center + 1, right, size, k);
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
  
void quickSort(int arr[], int low, int high, int k)  
{   
    int size = high - low + 1;
    if(size == k)
        insertionsort(arr, low, high);
    else if (low < high)  
    {  
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partition(arr, low, high);  
  
        // Separately sort elements before  
        // partition and after partition  
        quickSort(arr, low, pi - 1, k);  
        quickSort(arr, pi + 1, high, k);  
    }  
}  

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

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
 
void countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = { 0 };
 
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
 
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
 
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
 
void radixsort(int arr[], int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);
 
    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

void timSort(int arr[], int srt[], int n)
{
     
    // Sort individual subarrays of size RUN
    for (int i = 0; i < n; i+=RUN)
        insertionsort(arr, i, min((i+31), (n-1)));
 
    // Start merging from size RUN (or 32). 
    // It will merge
    // to form size 64, then 128, 256 
    // and so on ....
    for (int size = RUN; size < n; size = 2*size)
    {
         
        // pick starting point of 
        // left sub array. We
        // are going to merge 
        // arr[left..left+size-1]
        // and arr[left+size, left+2*size-1]
        // After every merge, we 
        // increase left by 2*size
        for (int left = 0; left < n; left += 2*size)
        {
             
            // find ending point of 
            // left sub array
            // mid+1 is starting point 
            // of right sub array
            int mid = left + size - 1;
            int right = min((left + 2*size - 1), 
                                            (n-1));
 
            // merge sub array arr[left.....mid] &
            // arr[mid+1....right]
            merge(arr, srt, left, mid, right, n);
        }
    }
}