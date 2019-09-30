#include <stdio.h>
#include <stdlib.h>
#define MAX_N 100001

typedef long long ll;

typedef struct {
  ll a;
  ll b;
} pair;

int comp_a(const void *c1,const void *c2);
int comp_b(const void *c1,const void *c2);

pair pair1[MAX_N] = {0};
pair pair2[MAX_N] = {0};

int p1_num;
int p2_num;

int main () {
  int N;
  int a;
  int b;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d %d",&a,&b);
    if(b > a){
      pair1[p1_num].a = a;
      pair1[p1_num].b = b;
      p1_num++;
    }else{
      pair2[p2_num].a = a;
      pair2[p2_num].b = b;
      p2_num++;
    }
  }

  /*for(int i=0;i<p1_num;i++){
    for(int j = i+1;j<p1_num;j++){
      if(pair1[i].a >  pair1[j].a){
        pair tmp = pair1[i];
	pair1[i] =  pair1[j];
	pair1[j] = tmp;
      }
    }
  }
  for(int i=0;i<p2_num;i++){
    for(int j = i+1;j<p2_num;j++){
      if(pair2[i].b >  pair2[j].b){
        pair tmp = pair2[i];
	pair2[i] =  pair2[j];
	pair2[j] = tmp;
      }
    }
  }*/
  qsort(pair1,p1_num,sizeof(pair),comp_a);
  qsort(pair2,p2_num,sizeof(pair),comp_b);
  ll MAX_X=0;
  ll X=0;
  for(int i=0;i<p1_num;i++){
    X += pair1[i].a;
    if(X > MAX_X){
      MAX_X = X;
    }
    X -= pair1[i].b;
  }
  for(int i=0;i<p2_num;i++){
    X += pair2[i].a;
    if(X > MAX_X){
      MAX_X = X;
    }
    X -= pair2[i].b;
  }
  printf("%lld\n",MAX_X);
}
int comp_a(const void *c1, const void *c2){
  pair p1 = *(pair *)c1;
  pair p2 = *(pair *)c2;

  ll t1 = p1.a;
  ll t2 = p2.a;

  return t1-t2;
}
int comp_b(const void *c1, const void *c2){
  pair p1 = *(pair *)c1;
  pair p2 = *(pair *)c2;

  ll t1 = p1.b;
  ll t2 = p2.b;

  return t2-t1;
} ./Main.c: In function ‘main’:
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:27:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&a,&b);
     ^