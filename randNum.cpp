#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) 
{
    string file = argv[1];
    int l = atoi(argv[2]);
    int h = atoi(argv[3]);
    ofstream myFile;
    myFile.open(file);
    
    srand((unsigned) time(0));
    unsigned long int randomNumber;
    for(int i = 0; i < 10; i++)
    {
        for (int index = 0; index < 1000000; index++) 
        {
            randomNumber = (rand() % h) + l;
            myFile << randomNumber << endl;
        }
        myFile << endl << endl << endl;
    }
    myFile.close();
    return 0;
}