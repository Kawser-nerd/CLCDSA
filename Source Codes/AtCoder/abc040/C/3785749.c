#include<stdio.h>
int dif(int a, int b);
int min(int a, int b);
int N, d[100000], i;
short H[100000];
int main(){
  scanf("%d", &N);
  for(i=0; i<N; i++){scanf("%d", H+i);}
  d[0]=0;
  d[1]=dif(H[0], H[1]);
  for(i=2; i<N; i++){
    d[i]=min(d[i-2]+dif(H[i-2], H[i]), d[i-1]+dif(H[i-1], H[i]));
  }
  printf("%d\n", d[N-1]);
}

int dif(int a, int b){
  return a<b?b-a:a-b;
}
int min(int a, int b){
  return a>b?b:a;
} ./Main.c: In function ‘main’:
./Main.c:8:28: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘short int *’ [-Wformat=]
   for(i=0; i<N; i++){scanf("%d", H+i);}
                            ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:8:22: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0; i<N; i++){scanf("%d", H+i);}
                      ^