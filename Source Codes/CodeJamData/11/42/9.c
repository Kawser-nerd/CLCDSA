#include <stdio.h>
#include <stdlib.h>

unsigned int W[500][500];
unsigned int Sx[500][500];
unsigned int Sy[500][500];
unsigned int Mx[500][500];
unsigned int My[500][500];

int main(int argc, char **argv) {
  int T,tc,R,C,K,i,j;
  unsigned int mx,my,tx;
  unsigned char wr;
  scanf("%d",&T);
  for(tc=1;tc<=T;++tc) {
    scanf("%d %d %*d ",&R,&C);
    for(j=0;j<R;++j) {
        for(i=0;i<C;++i) {
            scanf("%c", &wr);
            W[j][i]=wr-'0';
        }
        scanf(" ");
    }
    for(K=(R<C)?R:C;K>=3;--K) {
        for(i=0;i<C;++i) {
            mx=0; my=0;
            for(j=0;j<K;++j) {
                mx+=W[j][i];
                my+=(2*j-K+1)*W[j][i];
            }
            Sx[K-1][i]=mx;
            Sy[K-1][i]=my;
            for(j=K;j<R;++j) {
                my-=mx;
                mx+=W[j][i]-W[j-K][i];
                my+=(W[j][i]+W[j-K][i])*K;
                my-=mx;
                Sx[j][i]=mx;
                Sy[j][i]=my;
            }
        }
        for(j=K-1;j<R;++j) {
            mx=0; tx=0; my=0;
            for(i=0;i<K;++i) {
                mx+=(2*i-K+1)*Sx[j][i];
                tx+=Sx[j][i];
                my+=Sy[j][i];
            }
            Mx[j][K-1]=mx;
            My[j][K-1]=my;
            for(i=K;i<C;++i) {
                mx-=tx;
                mx+=(Sx[j][i]+Sx[j][i-K])*K;
                tx+=Sx[j][i]-Sx[j][i-K];
                my+=Sy[j][i]-Sy[j][i-K];
                mx-=tx;
                Mx[j][i]=mx;
                My[j][i]=my;
            }
        }
        for(j=K-1;j<R;++j) {
            for(i=K-1;i<C;++i) {
                mx=Mx[j][i]+(W[j-K+1][i-K+1]-W[j-K+1][i]+W[j][i-K+1]-W[j][i])*(K-1);
                my=My[j][i]+(W[j-K+1][i-K+1]+W[j-K+1][i]-W[j][i-K+1]-W[j][i])*(K-1);
                if((mx==0)&&(my==0)) {
                    printf("Case #%d: %d\n", tc, K);
                    goto nextcase;
                }
            }
        }
    }
    printf("Case #%d: IMPOSSIBLE\n", tc);
nextcase: 0;
  }
  return 0;
}

