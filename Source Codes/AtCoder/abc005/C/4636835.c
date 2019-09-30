#include<stdio.h>

int main(void)
{
  int t,n,m;
  int a[100];
  int b[100];
  int i,j=0;
  int judge=0;
  
  scanf("%d",&t);
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  scanf("%d",&m);
  for(i=0;i<m;i++){
    scanf("%d",&b[i]);
  }

  for(i=0;i<m;i++){
    
    while(1)
      {
	if(j==n){
	  printf("no\n");
	  return 0;
	}else if(b[i]-t<=a[j]&&b[i]>=a[j])
	  {
	    j++;
	    break;
	  }
	j++;
      }
  }
  printf("yes\n");
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&t);
   ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&m);
   ^
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&b[i]);
     ^