#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

void printArray(int* arr, int arrSize)                                         
{                                                                               
    for(int i = 0; i < arrSize; i++)                                            
     {                                                                           
         cout << arr[i] << " ";                                                  
     }                                                                           
     cout << "\n";                                                               
} 
int main ()
{
    int numVillages;
    int *villages;
    cin >> numVillages;
    villages = new int[numVillages];

    for(int i = 0; i < numVillages; i++)
    {
        cin >> villages[i];
    }

    sort(villages, villages + numVillages);
    double smallestNeighbourhood, tempNeighbourhood;
    bool smallestNeighbourhoodSet = false;
    
    for(int i = 1; i < numVillages - 1; i++)
    {
        tempNeighbourhood = (1.0 * villages[i] + 1.0 * villages[i+1])/2 - (1.0 * villages[i] + 1.0 * villages[i-1])/2;
        if(tempNeighbourhood < 0)
        {
           tempNeighbourhood *= -1;
        }

        if(!smallestNeighbourhoodSet)
        {
            smallestNeighbourhoodSet = true;
            smallestNeighbourhood = tempNeighbourhood;
        }
        else if (tempNeighbourhood < smallestNeighbourhood)
        {
            smallestNeighbourhood = tempNeighbourhood;
        }

    }

    cout << fixed << setprecision(1) << smallestNeighbourhood;
    return 0;
}

