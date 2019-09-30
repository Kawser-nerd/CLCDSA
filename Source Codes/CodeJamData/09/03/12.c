#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int m[35][510];
char s[510];
//char w[] = "abcd";
char w[] = "welcome to code jam";
int ls, lw;

void prt() {
  int i,j;
  for (i=0; i<=lw+1; i++) {
    printf("%c:",w[i]);
    for (j=0; j<=ls+1; j++) {
      printf(" %4d",m[i][j]);
    }
    printf("\n");
  }
  printf("\nTOTAL: %d\n",m[0][0]);
  printf("\n\n\n");
}

int main() {
  int N,n,i,j;
  lw = strlen(w);
  for (j=0;j<509;j++)
    m[lw][j] = 1;
  scanf("%d\n",&N);
  for (n=0;n<N;n++) {
    fgets(s,507,stdin);
    ls = strlen(s);

    memset(m,0,sizeof(m));
    for (j=0;j<509;j++)
      m[lw][j] = 1;
    


    for (i=0;i<lw;i++)
      m[i][ls] = 0;
    for (i=lw-1; i>=0; i--)
      for (j=ls-1; j>=0; j--) {
        m[i][j] = (m[i][j+1] + ((w[i]==s[j])? m[i+1][j+1] : 0))%10000;
      }
    //    prt();
    printf("Case #%d: %04d\n",n+1,m[0][0]%10000);
  }
}
