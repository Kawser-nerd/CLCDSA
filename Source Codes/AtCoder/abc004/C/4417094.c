#include<stdio.h>
int a[]={1,2,3,4,5,6};
void swap(int i,int j){
  int t;
  t=a[i];
  a[i]=a[j];
  a[j]=t;
}

int main(){
  int n,i=0;
  scanf("%d",&n);
  for(;i<n;i++){
    swap(i%5,i%5+1);
  }
  for(i=0;i<6;i++){
    printf("%d",a[i]);
  }
  puts("");
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^