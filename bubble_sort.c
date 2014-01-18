/*
Finish Date: 2014-1-11
Algorithm Name: Bubble Sort
Time Complexity:  O(n^2)
Space Complexity: O(1)
*/

#include "myheadfile.h"

void bubble_sort(int array[], int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=1;j<n;j++)
        {
            if(array[j-1]>array[j])
            {
                temp = array[j-1];
                array[j-1] = array[j];
                array[j] = temp;
            }
        }
    }
}

