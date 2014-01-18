
int partion(int array[], int low, int high)
{
    int temp;
    int t;
    int i;
    int j;
    t = array[low];
    for(i=low+1,j=low;i<=high;i++)
    {
        if(array[i]<t)
        {
            j++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    temp = array[low];
    array[low] = array[j];
    array[j] = temp;
    return j;
}

void quick_sort(int array[], int low, int high)
{
    int mid;
    if(low>=high)
    {
        return ;
    }
    mid = partion(array, low, high);
    quick_sort(array, low, mid-1);
    quick_sort(array, mid+1, high);
}
