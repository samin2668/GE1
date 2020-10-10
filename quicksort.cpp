#include "GE2.h"

int arr[1000000];
int temp[1000000];

int main()
{
    ifstream myFile;
    myFile.open("num1.txt");
    int num;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 1000000; j++)
        {
            myFile >> num;
            arr[j] = num;
        }
        auto begin = std::chrono::high_resolution_clock::now();
        int n = sizeof(arr) / sizeof(arr[0]);  
        quickSort(arr, 0, n - 1);
        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        cout << "Set " << i << ": " << elapsed.count() * 1e-9 << endl;
    }
    myFile.close();

    ofstream outFile;
    outFile.open("test.txt");
    for(int i = 0; i < 1000000; i++)
    {
        outFile << arr[i] << endl;
    }

    return 0;
}
