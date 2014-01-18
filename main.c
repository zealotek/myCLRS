#include <stdio.h>
#include "myheadfile.h"

void main()
{
    int a[]={5,4,6,7,1,2,0,8,9,3};
    int b[]={2,1};
    int i;
    //int max_left, max_right;
    //int sum;
    //insertion_sort(a,10);
    //merge_sort(a,0,9);
    //bubble_sort(a, 10);
    //sum = find_maximum_subarray_advance(a, 10, &max_left, &max_right);
    //printf("%d,%d,%d\n", sum, max_left, max_right);
    //heap_sort(a, 10);
    quick_sort(a, 0, 9);
    for(i=0;i<10;i++)
    {
        printf("%d,",a[i]);
    }
}
