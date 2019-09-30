#include <stdio.h>
#include <stdlib.h>
void quicksort(int data[],int left,int right); 
int main()
{
    	int n,h,i,j=0,ans=0,amax=0,flag=0;
    int a[1000000],b[1000000];
    	scanf("%d %d",&n,&h); 
    	for(i=0;i<n;i++)
    	{
        scanf("%d",&(a[i]));
        scanf("%d",&(b[i]));
        if(amax<a[i])amax=a[i];
    }
    quicksort(b,0,n-1);
    while(h>0&&j<n)
    {
        if(b[j]<amax)
        {
            flag=1;
            break;
        }
        h-=b[j];
        ans++;
        j++;
    }
    if(j==n||flag)
    {
        while(h>0)
        {
            h-=amax;
            ans++;
        }
    }
    printf("%d",ans);
}
void quicksort(int data[],int left,int right)
{
    int i,j;
    int std,work;
    	if(left<right)
    {
        i=left,j=right;
        std=data[(i+j)/2];//??
        do
        {
            while(data[i] > std)i++;
            while(data[j] < std)j--;
            	if(i<=j)
            {
                if(i<j)
                {
                    work=data[i];
                    data[i]=data[j];
                    data[j]=work;
                 }
                i++; j--;
            }
      }while(i<=j); 		if(left<j)quicksort(data,left,j); 		if(i<right)quicksort(data,i,right);
    }
} ./Main.c: In function ‘main’:
./Main.c:8:6: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
      scanf("%d %d",&n,&h); 
      ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&(a[i]));
         ^
./Main.c:12:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&(b[i]));
         ^