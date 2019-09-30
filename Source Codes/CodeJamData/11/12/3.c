#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char D[10000][11];
unsigned char L[100][27];
int CNT[10000][27];
int WL[10000];
int WA[10000];

int main(int argc, char **argv) {
  int T,tc,N,M,i,j,k,l,cl,hl,dx,lx,pl,mp,mpx,len;
  scanf("%d",&T);
  for(tc=1;tc<=T;++tc) {
    scanf("%d %d",&N,&M);
    for(i=0;i<N;++i) {
      scanf("%s", D[i]);
      WL[i]=strlen(D[i]);
      for(j=0;j<26;++j) CNT[i][j]=0;
      for(j=0;j<WL[i];++j) CNT[i][D[i][j]-'a']=1;
    }
    for(i=0;i<M;++i) {
      scanf("%s", L[i]);
    }
    printf("Case #%d:", tc);
    for(lx=0;lx<M;++lx) {
      mp=-1;
      mpx=-1;
      for(dx=0;dx<N;++dx) {
        len=WL[dx];
        pl=0;
        for(j=0;j<N;++j) {
          WA[j]=(WL[j]==len);
        }
        for(i=0;i<26;++i) {
          cl=L[lx][i];
          for(j=0;j<N;++j) {
            if(WA[j]) {
              if(CNT[j][cl-'a']) {
                if(CNT[dx][cl-'a']) {
                  for(k=0;k<N;++k) {
                    if(WA[k]) {
                      if(CNT[k][cl-'a']) {
                        for(l=0;l<len;++l) {
                          if((D[k][l]==cl)!=(D[dx][l]==cl)) {
                            WA[k]=0;
                            break;
                          }
                        }
                      } else {
                        WA[k]=0;
                      }
                    }
                  }
                } else {
                  ++pl;
                  for(k=0;k<N;++k) {
                    if(WA[k]) {
                      if(CNT[k][cl-'a']) {
                        WA[k]=0;
                      }
                    }
                  }
                }
                break;
              }
            }
          }
        }
        if(pl>mp) {
          mp=pl;
          mpx=dx;
        }
      }
      printf(" %s", D[mpx]);
    }
    printf("\n");
  }
  return 0;
}

