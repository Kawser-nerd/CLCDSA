#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int i,j,n,a[300000],mid,min,o,ans,mid2;
void qt(int l,int r)
{
    int i,j,m,p;
    i=l; j=r;
    m=a[(l+r)/2];
    while (i<=j)
    {
        while (a[i]<m) i++;
        while (a[j]>m) j--;
        if (i<=j)
        {
            p=a[i];a[i]=a[j]; a[j]=p;
            i++; j--;
        }
    }
if (i<r) qt(i,r);
if (l<j) qt(l,j);
}

int main()
{
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    scanf("%d",&a[i]);
    qt(1,n);
    mid=a[n]/2;
    if (a[n]%2==1)
    {
        mid2=a[n]/2+1;
        min=1000000010;
        for (i=1;i<=n;i++)
        {
          o=a[i]-mid;
          if (o<0) o=-o;
          if (o<min) {min=o; ans=a[i];}
        }
        min=1000000010;
        for (i=1;i<=n;i++)
        {
          o=a[i]-mid2;
          if (o<0) o=-o;
          if (o<min) {min=o; ans=a[i];}
        }
        printf("%d %d",a[n],ans);
    } else
   {
     min=1000000010;
      for (i=1;i<=n;i++)
      {
         o=a[i]-mid;
         if (o<0) o=-o;
         if (o<min) {min=o; ans=a[i];}
      }
      printf("%d %d",a[n],ans);
   }
    return(0);
} ./Main.c: In function ‘main’:
./Main.c:26:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:28:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^