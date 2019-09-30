#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int i,j,n,a[300000],b[300000],c[300000];
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
            p=b[i]; b[i]=b[j]; b[j]=p;
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
    {
        scanf("%d",&a[i]);
        b[i]=i;
    }
    qt(1,n);
    for (i=1;i<=n;i++)
        c[b[i]]=i;
    for (i=1;i<=n;i++)
    {
        if (c[i]<=(n/2)) printf("%d\n",a[(1+n)/2+1]); else printf("%d\n",a[(1+n)/2]);
    }
    return(0);
} ./Main.c: In function ‘main’:
./Main.c:27:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:30:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^