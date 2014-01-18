/*
Finish Date: 2014-1-11
Algorithm Name: Merge Sort
Time Complexity:  O(n^2)
Space Complexity: O(n)
*/
#include "myheadfile.h"

void merge(int array[], int p, int q, int t)
{
    int temp[t-p+1];
    int i = p, j = q, k = 0;
    while((i<=q-1)&&(j<=t))
    {
        if(array[i]<=array[j])
        {
            temp[k] = array[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = array[j];
            k++;
            j++;
        }
    }
    if(i==q)
    {
        while(j<=t)
        {
            temp[k] = array[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<=q-1)
        {
            temp[k] = array[i];
            i++;
            k++;
        }
    }

    for(i=0,j=p;i<t-p+1;i++,j++)
    {
        array[j] = temp[i];
    }
}

void merge_sort(int array[], int m, int n)
{
    int temp = (m+n)/2;
    if(m == n)
    {
        return ;
    }
    merge_sort(array,m,temp);
    merge_sort(array,temp+1,n);
    merge(array,m,temp+1,n);
}
