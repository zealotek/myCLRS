/*
Finish Date: 2014-1-12
Algorithm Name: find maximum sub array
Time Complexity:  O(n*lg(n))
Space Complexity:
*/

//array[low~mid] array[mid+1~high]
int find_max_cross_subarray(int array[], int low, int mid, int high, int *max_left, int *max_right)
{
    int sum = 0;
    int i;
    int left_sum = 0;
    int right_sum = 0;
    *max_left = mid-1;
    *max_right = mid;

    for(i=mid;i>=low;i--)
    {
        sum += array[i];
        if(left_sum < sum)
        {
            left_sum = sum;
            *max_left = i;
        }
    }

    sum = 0;
    for(i=mid+1;i<=high;i++)
    {
        sum += array[i];
        if(right_sum < sum)
        {
            right_sum = sum;
            *max_right = i;
        }
    }

    return (right_sum + left_sum);
}

int find_maximum_subarray(int array[], int low, int high, int *max_left, int *max_right)
{
    int mid;
    int sum = 0,max_sum = 0;
    int left,right;
    if(low == high)
    {
        *max_left = low;
        *max_right = low;
        return array[low];
    }
    mid = (low + high)/2;

    max_sum = find_maximum_subarray(array, low, mid, &left, &right);
    *max_left = left;
    *max_right = right;

    sum = find_maximum_subarray(array, mid+1, high, &left, &right);
    if(max_sum < sum)
    {
        max_sum = sum;
        *max_left = left;
        *max_right = right;
    }

    sum = find_max_cross_subarray(array, low, mid, high, &left, &right);
    if(max_sum < sum)
    {
        max_sum = sum;
        *max_left = left;
        *max_right = right;
    }
    return max_sum;
}

/*
Finish Date: 2014-1-12
Algorithm Name: Advance find maximum sub array
Time Complexity:  O(n)
Space Complexity:
*/

int find_maximum_subarray_advance(int array[], int n, int *max_left, int *max_right)
{
    int maxsofar = 0;
    int max_line = 0;
    int i;
    int left;
    int right;
    left = 0;
    right = -1;
    *max_left = -1;
    *max_right = -1;
    for(i=0;i<n;i++)
    {
        max_line += array[i];
        right = i;
        if(max_line < 0)
        {
            left = i+1;
            right = i+1;
            max_line = 0;
        }
        else if(max_line > maxsofar)
        {
            maxsofar = max_line;
            *max_left = left;
            *max_right = right;
        }
    }
    return maxsofar;
}
