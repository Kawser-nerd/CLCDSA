#include<stdio.h>

int ceil(int a,int b){if(a%b==0){return a/b;}return (a/b)+1;}

void prarr(int arr[],int n){
  int i;
  for(i=0;i<n;i++){
    if(i){printf(" ");}
    printf("%d",arr[i]);
  }
  printf("\n");
  return;
}

int main(void){
    int i,j,n,m,k,a[512][512],b,c,h,w,r=0,l,t;
    scanf("%d",&k);
    if(k==1){
      printf("1\n1\n");
      return 0;
    }
    n=ceil(k,2);
    if(n%2==1){n++;}
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
        a[i][j]=((i+j)%n)+1;
        if(i%2){
          a[i][j]+=n;
        }
        if(a[i][j]>k){a[i][j]-=n;}
      }
    }
    printf("%d\n",n);
    for(i=0;i<n;i++){
      prarr(a[i],n);
    }
    return 0;
} ./Main.c:3:5: warning: conflicting types for built-in function ‘ceil’
 int ceil(int a,int b){if(a%b==0){return a/b;}return (a/b)+1;}
     ^
./Main.c: In function ‘main’:
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&k);
     ^