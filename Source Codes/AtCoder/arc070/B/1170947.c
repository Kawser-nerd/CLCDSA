#include<stdio.h>

void QSort(int x[ ], int left, int right);
void Swap(int x[ ], int i, int j);
void reverse(int array[], int length);

void QSort(int x[ ], int left, int right)
{
    int i, j;
    int pivot;
    i = left;                      
    j = right;
    pivot = x[(left + right) / 2]; 
    while (1) {                    
        while (x[i] < pivot)       
            i++;

        while (pivot < x[j])       
            j--;                 
        if (i >= j)              
            break;              

        Swap(x, i, j);            
        i++;                       
        j--;
    }
    
    if (left < i - 1)              
        QSort(x, left, i - 1);    
    if (j + 1 <  right)            
        QSort(x, j + 1, right);    
}

void Swap(int x[ ], int i, int j)
{
    int temp;
    temp = x[i];
    x[i] = x[j];
    x[j] = temp;
}

void reverse(int array[], int length)
{
    int i, j;
    int temp;
    
    for( i = 0, j = length - 1; i < j; i++, j-- )
    {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

int main (void) {
  int N,K;
  scanf("%d %d",&N,&K);
  int a[5010];
  int i,j;
  for(i=0;i<N;i++){
    scanf("%d",&a[i]);
    if(a[i]>=5000){
      N--;
      i--;
    }
  }

  QSort(a, 0, N-1);
  reverse(a,N);

  int left,right,point;
  int sum;
  int check = 0;
  point = -1;
  for(left=0;left<N;left++){
    sum = 0;
    for(right=left;right<N;right++){
      sum += a[right];
      if(sum>=K){
	point = right;
	sum -= a[right];
      } else {
	if(right==N-1){
	  //check = 1;
	}
      }
    }
    if(check){
      break;
    }
  }
  
  printf("%d\n",N-point-1);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:57:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&N,&K);
   ^
./Main.c:61:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^