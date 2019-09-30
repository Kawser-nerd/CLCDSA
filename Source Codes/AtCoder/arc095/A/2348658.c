#include<stdio.h>
#include<stdlib.h>

struct pair{
  int num,data,ans;
};

int compdata(const void *p1,const void *p2){
  int n1=((const struct pair *)p1)->data;
  int n2=((const struct pair *)p2)->data;
  return n1-n2;
}

int compnum(const void *p1,const void *p2){
  int n1=((const struct pair *)p1)->num;
  int n2=((const struct pair *)p2)->num;
  return n1-n2;
}


int main(void){
  int N;
  struct pair array[200000];
  int i,j,k;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&array[i].data);
    array[i].num=i;
  }
  qsort(array,N,sizeof(struct pair),compdata);
  for(i=0;i<N/2;i++) array[i].ans=array[N/2].data;
  for(i=N/2;i<N;i++) array[i].ans=array[N/2-1].data;
  qsort(array,N,sizeof(struct pair),compnum);
  for(i=0;i<N;i++) printf("%d\n",array[i].ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:27:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&array[i].data);
     ^