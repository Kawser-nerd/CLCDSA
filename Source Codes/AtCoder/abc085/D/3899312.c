#include<stdio.h>
void Swap(long x[ ], int i, int j)
{
    long temp;
    temp = x[i];
    x[i] = x[j];
    x[j] = temp;
}
void QSort(long x[ ], int left, int right)
{
    int i, j;
    long pivot;
    i = left;                     
    j = right;                    
    pivot = x[(left + right) / 2]; 
    while (1) 
    {    while (x[i] < pivot)      
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
int main(){
  int n,i,j,aaa;;
  long h,a[100000],b[100000],max=0,temp,cnta=0,cntb=0,cnt;
  scanf("%d %ld",&n,&h);
  for(i=0;i<n;i++){ 
    scanf("%ld %ld",&a[i],&b[i]);
    if(max<a[i]) max=a[i];
  }
  QSort(b, 0, n - 1);
  for(i=n-1;i>=0;i--){
    if(max<b[i]){
      h-=b[i];
      cntb++;
    }
    else break;
    if(h<=0) break;
  }
  if(h<=0)  cnta=0;
  else if(h%max!=0)  cnta=(h/max)+1;
  else cnta=h/max;
  cnt=cnta+cntb;
  printf("%ld\n",cnt);
} ./Main.c: In function ‘main’:
./Main.c:35:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %ld",&n,&h);
   ^
./Main.c:37:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld %ld",&a[i],&b[i]);
     ^