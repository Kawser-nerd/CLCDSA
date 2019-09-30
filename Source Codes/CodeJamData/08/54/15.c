#include <stdio.h>
#include <stdlib.h>
#define MAX 110

int qtd[MAX][MAX];
int w,h,r;
int pode[MAX][MAX];

int main(){
  int nt,nt0;
  int i,j,k;

  scanf(" %d", &nt0);
  for(nt=1 ; nt<=nt0 ; nt++){
    scanf(" %d %d %d", &h,&w,&r);

    for(i=0 ; i<h ; i++)
      for(j=0 ; j<w ; j++){
	pode[i][j]=1;
	qtd[i][j]=0;
      }

    for(i=0 ; i<r ; i++){
      scanf(" %d %d", &j,&k);
      pode[j-1][k-1]=0;
    }

    qtd[0][0]=1;
    for(i=0 ; i<h ; i++)
      for(j=0 ; j<w ; j++)
	if(qtd[i][j] && pode[i][j]){
	  qtd[i+2][j+1] = (qtd[i+2][j+1]+qtd[i][j])%10007;
	  qtd[i+1][j+2] = (qtd[i+1][j+2]+qtd[i][j])%10007;
	}

    printf("Case #%d: %d\n", nt,qtd[h-1][w-1]);
  }

  return 0;
}
