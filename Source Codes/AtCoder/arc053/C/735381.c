#include<stdio.h>
#include<stdlib.h>

struct mag{
  int a,b;
};

int down_comp(const void *p1,const void *p2);
int up_comp(const void *p1,const void *p2);

int main(void){
  struct mag down[100000],eq[100000],up[100000];
  int N,i,j,k,a,b;
  int nd=0,ne=0,nu=0;
  long long int temp=0,max=0;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d%d",&a,&b);
    if(a<b) down[nd++]=(struct mag){a,b};
    else if(a==b) eq[ne++]=(struct mag){a,b};
    else up[nu++]=(struct mag){a,b};
  }

  qsort(down,nd,sizeof(down[0]),down_comp);

  for(i=0;i<nd;i++){
    temp+=down[i].a;
    if(temp>max) max=temp;
    temp-=down[i].b;
  }

  for(i=0;i<ne;i++) if(eq[i].a+temp>max) max=eq[i].a+temp;

  qsort(up,nu,sizeof(up[0]),up_comp);
  for(i=0;i<nu;i++){
    temp+=up[i].a;
    if(temp>max) max=temp;
    temp-=up[i].b;
  }
  printf("%lld\n",max);

  return 0;
}

int down_comp(const void *p1,const void *p2){
  struct mag n1,n2;
  n1=*(const struct mag *)p1;
  n2=*(const struct mag *)p2;
  if(n1.a<n2.a) return -1;
  else return 1;
}

int up_comp(const void *p1,const void *p2){
  struct mag n1,n2;
  n1=*(const struct mag *)p1;
  n2=*(const struct mag *)p2;
  if(n1.b<n2.b) return 1;
  return -1;
} ./Main.c: In function ‘main’:
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^