#include<stdio.h>

void qsort(int x[],int left,int right);
void swap(int x[],int i,int j);

int main(void)
{
  int n;
  int k;
  int r[4000];
  int i;
  double sum=0;

  scanf("%d%d",&n,&k);
  for(i=0;i<n;i++){
    scanf("%d",&r[i]);
  }

  qsort(r,0,n-1);

  for(i=n-k;i<n;i++)
    {
      sum=(sum+r[i])/2.0;
    }
  printf("%f\n",sum);
  
  return 0;
}


void qsort(int x[],int left,int right)
{
  int i=left;
  int j=right;
  int pivot;

  pivot=x[(left+right)/2];

  while(1){
    while(x[i]<pivot){
      i++;
    }
    while(x[j]>pivot){
      j--;
    }
    if(i>=j)
      break;

    swap(x,i,j);
    i++;
    j--;
  }

  if(left<i-1)
    {
      qsort(x,left,i-1);
    }
  if(right>j+1){
      qsort(x,j+1,right);
    }
    

}

void swap(int x[],int i,int j)
{
  int temp;
  temp=x[i];
  x[i]=x[j];
  x[j]=temp;
} ./Main.c: In function ‘main’:
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&k);
   ^
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&r[i]);
     ^