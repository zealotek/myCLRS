/*
Finish Date: 2014-1-11
Algorithm Name: Insertion Sort
Time Complexity:  O(n) - O(n^2)
Space Complexity: O(1)
*/
#include "myheadfile.h"

void insertion_sort(int array[], int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        for(j=i;j>0;j--)
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
