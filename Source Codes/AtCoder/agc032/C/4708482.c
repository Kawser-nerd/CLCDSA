#include <stdio.h>
#define N_MAX 131072
#define A(I)  (edge[(I)]/N_MAX)
#define B(I)  (edge[(I)]%N_MAX)
void QSort(int left,int right);
long edge[200001];
int main(void) {
  long N,M,wait_v[100001]={},v4[2],index[100001],j,temp,temp2,a,b,num_v4=0;
  scanf("%ld %ld",&N,&M);
  for(int i=1;i<=M;i++){
    scanf("%ld %ld",&a,&b);
    edge[i]=a*N_MAX+b;
    edge[i+M]=b*N_MAX+a;
    wait_v[a]++;
    wait_v[b]++;    
  }
//  printf("\n");
//  for(int i=1;i<=2*M;i++){printf("%ld %ld\n",A(i),B(i));}
//  printf("\n");  
//  for(int i=1;i<=N;i++){printf("%d\n",wait_v[i]);}
  for(int i=1;i<=N;i++){
    if(wait_v[i]%2==1){
      printf("No");
      return 0;
    }
  }
  for(int i=1;i<=N;i++){
    if(wait_v[i]>=6){
      printf("Yes");
      return 0;
    }else if(wait_v[i]==4){
      if(num_v4==2){
        printf("Yes");
        return 0;
      }
      v4[num_v4++]=i;
    }
  }
  if(num_v4==2){
//    printf("\n%d %d\n",v4[0],v4[1]);
    QSort(1,2*M);
//    printf("\n");
//    for(int i=1;i<=2*M;i++){printf("%ld %ld\n",A(i),B(i));}
    j=1;
    for(int i=1;i<=N;i++){
      while(A(j)!=i){j++;}
      index[i]=j;
    }
//    for(int i=1;i<=N;i++){printf("%d\n",index[i]);}
    for(int i=0;i<3;i++){
      temp=B(index[v4[0]]+i);
      temp2=v4[0];
//      printf("%d %d\n",temp,temp2);
      while((temp!=v4[0])&&(temp!=v4[1])){
        if(B(index[temp])==temp2){
          temp2=temp;
          temp=B(index[temp]+1);
        }
        else{
          temp2=temp;
          temp=B(index[temp]);
        }
//        printf("%d %d\n",temp,temp2);
      }
      if(temp==v4[0]){
        printf("Yes");
        return 0;
      }
    }
  }
  printf("No");
  return 0;
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
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld %ld",&N,&M);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld %ld",&a,&b);
     ^