#include <stdio.h>
#define N_MAX 131072
#define A(I)  (edge[(I)]/N_MAX)
#define B(I)  (edge[(I)]%N_MAX)
void QSort(int left,int right);
char* ans(void);
long edge[200001];
int main(void){
  printf("%s",ans());
  return 0;
}
char* ans(void){
  int N,M,wait_v[100001]={},index[100001],v4[2],temp,temp2,j,num_v4=0;
  scanf("%d %d",&N,&M);
  for(int i=1;i<=M;i++){
    scanf("%d %d",&temp,&temp2);
    edge[i]=(long)temp*N_MAX+temp2;
    edge[i+M]=(long)temp2*N_MAX+temp;
    wait_v[temp]++;
    wait_v[temp2]++;    
  }
  for(int i=1;i<=N;i++){if(wait_v[i]%2==1){return "No";}}
  for(int i=1;i<=N;i++){if(wait_v[i]>=6){return "Yes";}}
  for(int i=1;i<=N;i++){if(wait_v[i]==4){v4[num_v4++]=i;}}
  if(num_v4>=3){return "Yes";}
  else if(num_v4==2){
    QSort(1,2*M);
    j=1;
    for(int i=1;i<=N;i++){
      while(A(j)!=i){j++;}
      index[i]=j;
    }
    for(int i=0;i<3;i++){
      temp=B(index[v4[0]]+i);
      temp2=v4[0];
      while((temp!=v4[0])&&(temp!=v4[1])){
        if(B(index[temp])==temp2){
          temp2=temp;
          temp=B(index[temp]+1);
        }
        else{
          temp2=temp;
          temp=B(index[temp]);
        }
      }
      if(temp==v4[0]){return "Yes";}
    }
  }
  return "No";
}

void QSort(int left,int right)
{
  int i,j;
  long a_center,temp;
  i=left;
  j=right;
  a_center=edge[(left+right)/2];
  while(1){
      while(edge[i]<a_center){i++;}
      while(a_center<edge[j]){j--;}
      if(i>=j){break;}
      temp=edge[i];
      edge[i]=edge[j];
      edge[j]=temp;
      i++;
      j--;
  }
  if (left<i-1){QSort(left,i-1);} 
  if (j+1<right){QSort(j+1,right);}
} ./Main.c: In function ‘ans’:
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&N,&M);
   ^
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&temp,&temp2);
     ^