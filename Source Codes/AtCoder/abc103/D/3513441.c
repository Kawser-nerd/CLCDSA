#include<stdio.h>
#define SIZE 100000
void Swap(int a[],int b[],int i,int j);
void Qsort(int a[],int b[],int bottom,int up);

int main(){
  int n,m,a[SIZE],b[SIZE];
  int i;
  int x,counter=1;
  scanf("%d%d",&n,&m);
  for(i=0;i<m;i++){
    scanf("%d%d",&a[i],&b[i]);
  }
  Qsort(a,b,0,m-1);
  x=b[0]-1;
  for(i=1;i<m;i++){
    if(x<a[i]){
      counter++;
      x=b[i]-1;
    }
  }
  printf("%d\n",counter);


  return 0;
}

void Swap(int a[],int b[],int i,int j){
  int temp;
  temp=a[i];
  a[i]=a[j];
  a[j]=temp;
  temp=b[i];
  b[i]=b[j];
  b[j]=temp;
}  

void Qsort(int a[],int b[],int bottom,int up){
  int i,j,k;
  int pivot;
  
  i=bottom;
  j=up;
  pivot=b[(bottom+up+1)/2];
  
  while(1){
    while(b[i]<pivot) i++; //???pivot??????
    while(b[j]>pivot) j--; //???pivot??????
    if(i>=j) break; //???????????
    
    Swap(a,b,i,j);
    i++;
    j--;
  }
  if(bottom<i-1) Qsort(a,b,bottom,i-1); //?????????2???????Qsort
  if(i<up) Qsort(a,b,i,up); //????????2???????sort
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a[i],&b[i]);
     ^