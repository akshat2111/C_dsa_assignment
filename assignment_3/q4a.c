#include <stdio.h>


void swap(int *a,int *b)
{
    int temp= *a;
    *a=*b;
     *b= temp;
}

void selectionsort(int a[],int n)
{
    int i,j;
    for(i=0; i<n;i++)
    {
        int max = i;
        j= i+1;
        while(j<n)
        {
            if(a[j]>a[max])
            max = j;
            j++;
        }
        swap(&a[max],&a[i]);
    }
}

int main ()
{
    int a[5]= {1,2,3,4,5};
    int n= sizeof(a)/sizeof(a[0]),i;
    selectionsort(a,n);
    for(i=0; i<n;i++)
    {
        printf("%d ",a[i]);
    }

}