#include<stdio.h>
#include<stdlib.h>

#define SENTINEL 1000000001

int nibutan(int left,int right,int num,int s[]){
	int nibun=(left+right)/2;
	if(num>s[nibun])
	{
		if(right-left==1)
		{
			return right;
		}
		return nibutan(nibun,right,num,s);
	}else if(num<s[nibun])
	{
		return nibutan(left,nibun,num,s);
	}else
	{
		return nibun;
	}
	
}

int count=0;

void merge(int A[],int left,int mid,int right);

void mergeSort(int A[],int left,int right){
  int i,mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}



void merge(int A[],int left,int mid,int right){
  int n1,n2,i,j,k;
  int *L,*R;
  n1=mid-left;
  n2=right-mid;
  L=(int *)malloc(sizeof(int)*(n1+1));
  R=(int *)malloc(sizeof(int)*(n2+1));
  for(i=0;i<=n1-1;i++){
    L[i]=A[left+i];
  }
  for(j=0;j<=n2-1;j++){
    R[j]=A[mid+j];
  }
  L[n1]=SENTINEL;
  R[n2]=SENTINEL;
  i=0;
  j=0;
  for(k=left;k<=right-1;k++){
   if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
      count++;
    }
    else{
      A[k]=R[j];
      j++;
      count++;
    }
  }
  free(L);
  free(R);
}


int main(){
  int A[200000];
  int sortA[200000];
  int n,result=0;

  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&A[i]);
    sortA[i]=A[i];
  }
  mergeSort(sortA,0,n);
  
  for(int i=0;i<n;i++)
  {
  	if(i%2!=nibutan(0,n-1,A[i],sortA)%2)
  	{
  		result++;
  	}
  }
  printf("%d",result/2);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:80:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:82:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&A[i]);
     ^