#include<stdio.h>
#include<stdlib.h>
void over_b(int i,int *p,int *q);
int main(void)
{
    int n,i;
    scanf("%d",&n);
    int b[n],a[n];
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    over_b(n-1,b,a);
    for(i=0;i<n;i++)
    printf(" %d",b[i]);
}
void over_b(int i,int *p,int *q)
{
    int j=0,z=i;
    if(i%2==0)
while(i>=0){
    if(i%2==0) p[j]=q[i];
    else {p[z]=q[i]; z--; j--; }
    i--;
    j++;
    }
  else
while(i>=0){
    if(i%2!=0) p[j]=q[i];
    else {p[z]=q[i]; z--; j--;}
    i--;
    j++;
    }
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^