#include <stdio.h>

int arr[5000000];
int left[2500000],right[2500000];

void merge(int *arr, int front, int mid, int end)
{
    int lindex = 0,rindex = 0;
    for(int i = front;i <= mid ;++i)
        left[lindex++] = arr[i];
    for(int i = mid+1;i < end ;++i)
        right[rindex++] = arr[i];
    lindex = rindex = 0;
    for(int i = front;i < end ;++i)
    {
        if(left[lindex] < right[rindex])
            arr[i] = left[lindex++];
        else
            arr[i] = right[rindex++];
    }
}
void mergesort(int *arr,int front, int end)
{
    if(front < end)
    {
        int mid = (front + end) / 2;
        mergesort(arr,front,mid);
        mergesort(arr,mid+1,end);
        merge(arr,front,mid,end);
    }
}

int main()
{
    int n,k,index = 0;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&k);
        for(int j=0;j<k;++j)
            scanf("%d",&arr[index++]);
    }
    mergesort(arr,0,index);
    for(int i=0;i<index;++i)
        printf("%d\n",arr[i]);
    return 0;
}
