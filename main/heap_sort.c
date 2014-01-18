
void max_heapify(int array[], int n, int target)
{
    int largest;
    int temp = array[target];

    while(target*2 < n)
    {
        if((target*2+1<n) && (array[target*2] < array[target*2+1]))
        {
            largest = target*2 + 1;
        }
        else
        {
            largest = target*2;
        }

        if(temp < array[largest])
        {
            array[target] = array[largest];
            target = largest;
        }
        else
        {
            break;
        }
    }
    array[target] = temp;
}

void build_max_heap(int array[], int n)
{
    int i = n/2;
    while(i>0)
    {
        max_heapify(array, n, i);
        i--;
    }
}

void heap_sort(int array[], int n)
{
    int i = n-1;
    int temp;
    build_max_heap(array,n);

    int j;
    for(j=0;j<10;j++)
    {
        printf("%d,",array[j]);
    }
    printf("\n");

    temp = array[i];
    array[i] = array[1];
    array[1] = temp;
    i--;
    n--;

    while(i>0)
    {
        max_heapify(array, n, 1);
        temp = array[i];
        array[i] = array[1];
        array[1] = temp;
        i--;
        n--;
    }
}

int heap_extract_max(int array[], int n, int target)
{
    int max;
    if(n<=0)
    {
        return -1;
    }
    max = array[1];
    array[1] = array[n-1];
    n--;
    max_heapify(array, n, 1);
    return max;
}

int heap_update_key(int array[], int n, int target, int key)
{
    if(target>=n)
    {
        return -1;
    }
    if(array[target] > key)
    {
        array[target] = key;
        max_heapify(array, n, target);
    }
    else
    {
        array[target] = key;
    }
}

//max_heap_insert()

