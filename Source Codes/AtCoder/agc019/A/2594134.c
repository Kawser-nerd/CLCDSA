#include <stdio.h>
int main(void) {
 long long int Q,H,S,D,N,twoL,Sum=0,YJ,oneL;
 scanf("%ld%ld%ld%ld",&Q,&H,&S,&D);
 scanf("%ld",&N);
 oneL=S;
if(oneL>2*H){oneL=2*H;};
if(oneL>4*Q){oneL=4*Q;};
if(2*oneL>D){twoL=D;}
else{twoL=2*oneL;}
Sum=(N-(N%2))/2*twoL+N%2*oneL;
 printf("%ld\n",Sum);
 return 0;
 } ./Main.c: In function ‘main’:
./Main.c:4:8: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 2 has type ‘long long int *’ [-Wformat=]
  scanf("%ld%ld%ld%ld",&Q,&H,&S,&D);
        ^
./Main.c:4:8: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 3 has type ‘long long int *’ [-Wformat=]
./Main.c:4:8: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 4 has type ‘long long int *’ [-Wformat=]
./Main.c:4:8: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 5 has type ‘long long int *’ [-Wformat=]
./Main.c:5:8: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 2 has type ‘long long int *’ [-Wformat=]
  scanf("%ld",&N);
        ^
./Main.c:12:9: warning: format ‘%ld’ expects argument of type ‘long int’, but argument 2 has type ‘long long int’ [-Wformat=]
  printf("%ld\n",Sum);
         ^
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-...