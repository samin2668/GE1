#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) 
{
    string file = argv[1];
    ofstream myFile;
    myFile.open(file);
    
    srand((unsigned) time(0));
    int randomNumber;
    for(int i = 0; i < 10; i++)
    {
        for (int index = 0; index < 1000000; index++) 
        {
            randomNumber = (rand() % 10) + 1;
            myFile << randomNumber << endl;
        }
        myFile << endl << endl << endl;
    }
    myFile.close();
    return 0;
}