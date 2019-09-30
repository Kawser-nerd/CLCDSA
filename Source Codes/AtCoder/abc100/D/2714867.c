#include<stdio.h>

int main(){
long int a[8][1000],b[8][1000],c[8];
long int i,j,k,p,q,r,tmp,N,M;

scanf("%ld %ld",&N,&M);
for(i=0;i<1000;i++){
scanf("%ld %ld %ld",&p,&q,&r);
a[0][i]=p+q+r;
a[1][i]=p+q-r;
a[2][i]=p-q+r;
a[3][i]=p-q-r;
a[4][i]=-p+q+r;
a[5][i]=-p+q-r;
a[6][i]=-p-q+r;
a[7][i]=-p-q-r;
}
for(i=0;i<8;i++){
for(j=0;j<N;j++){
b[i][j]=a[i][j];
}
}

for(k=0;k<8;k++){
for (i=0; i<N; ++i) {
    for (j=i+1; j<N; ++j) {
      if (b[k][i] < b[k][j]) {
        tmp =  b[k][i];
        b[k][i] = b[k][j];
        b[k][j] = tmp;
      }
    }
  }
}

for(k=0;k<8;k++){
for(i=0;i<M;i++){
c[k]=c[k]+b[k][i];
          }
}

for (i=0; i<8; ++i) {
    for (j=i+1; j<8; ++j) {
      if (c[i] < c[j]) {
        tmp =  c[i];
        c[i] = c[j];
        c[j] = tmp;
      }
    }
  }

printf("%ld",c[0]);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%ld %ld",&N,&M);
 ^
./Main.c:9:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%ld %ld %ld",&p,&q,&r);
 ^