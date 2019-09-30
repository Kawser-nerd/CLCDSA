#include<stdio.h>

int main(void)
{
  int a,b,n,i,j,max,max1=0;
  int count[1000002]={0};

  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    scanf("%d %d",&a,&b);
    count[a]++;
    count[b+1]--;
    max1=max1>a?max1:a;
    max1=max1>b?max1:b;
  }
  
    max=count[0];
  for(i=1;i<=max1;i++)
    {
      count[i]+=count[i-1];
    if(max<count[i]){
      max=count[i];
    }
  }
  printf("%d\n",max);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&a,&b);
     ^