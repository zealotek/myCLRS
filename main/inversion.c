/*
Finish Date: 2014-1-12
Algorithm Name: Inversion Check
Time Complexity:  O(n*lg(n))
Space Complexity:
*/
#include "myheadfile.h"

int inversion_merge(int array[], int p, int q, int t)
{
    int mult = q-p,count = 0;
    int temp[t-p+1];
    int i = p, j = q, k = 0;
    while((i<=q-1)&&(j<=t))
    {
        if(array[i]<=array[j])
        {
            temp[k] = array[i];
            k++;
            i++;
            mult--;
        }
        else
        {
            temp[k] = array[j];
            k++;
            j++;
            count += mult;
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
    return count;
}

int inversion_merge_sort(int array[], int m, int n)
{
    int temp = (m+n)/2;
    int count = 0;
    if(m == n)
    {
        return 0;
    }
    count += inversion_merge_sort(array,m,temp);
    count += inversion_merge_sort(array,temp+1,n);
    return (count + inversion_merge(array,m,temp+1,n));
}

int inversion(int array[],int n)
{
    return inversion_merge_sort(array,0,n-1);
}
