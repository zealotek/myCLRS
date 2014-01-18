/*
Finish Date: 2014-1-12
Algorithm Name: Horner rules 多项式的线性算法
Time Complexity:  O(n)
Space Complexity: O(1)
*/
int horner(int a[], int n, int x)
{
    int result = 0;
    int i;
    for(i=0;i<n;i++)
    {
        result = a[i] + result*x;
    }
    return result;
}
