#include<stdio.h>

int ans=0;

void count(int*,int,int);
void pluser(int*,int,int);

void pluser(int array[],int left,int right){
  int pivot=array[left];
  int i;
  for(i=left;i<=right;i++){
    if(array[i]<pivot)pivot=array[i];
  }
  for(i=left;i<=right;i++){
    array[i]-=pivot;
  }
  ans+=pivot;
  count(array,left,right);
}

void count(int array[],int left,int right){
  int i,j,c;
  j=1;
  c=0;
  for(i=left;i<=right;i++){
    if(array[i]==0)c++;
  }
  int zero[c+2];
  zero[0]=left-1;
  zero[c+1]=right+1;
  for(i=left;i<=right;i++){
    if(array[i]==0){
      zero[j]=i;
      j++;
    }
  }

  if(c==0){
    pluser(array,left,right);
  }
  for(i=0;i<c+1;i++){
    if(zero[i]+1==zero[i+1]){
      continue;
    }else if(zero[i]+2==zero[i+1]){
      ans+=array[zero[i]+1];
      array[zero[i]+1]=0;
    }else{
      pluser(array,zero[i]+1,zero[i+1]-1);
    }
  }

}

int main(void){
  int n,i,j,ze;
  j=1;
  while(scanf("%d",&n)!=1);
  int array[n];
  for(i=0;i<n;i++){
    while(scanf("%d",&array[i])!=1);
  }
  count(array,0,n-1);
  printf("%d\n",ans);

  return 0;
}