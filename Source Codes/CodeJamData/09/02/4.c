#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 256
#define INF 123123123

int k,h,w;
int x[]={-1,0,0,1};
int y[]={0,-1,1,0};
int mapa[TAM][TAM];
int sink[TAM][TAM];

int valido(int px,int py){
  if(px < 0 || px>=h) return 0;
  if(py < 0 || py>=w) return 0;
  return 1;
}

void DFS(int px,int py){
  int i,menor,prox;
  int ppx,ppy;

  if(sink[px][py]!=-1) return;
  menor = INF;
  prox = -1;
  for(i=0;i<4;i++){
    ppx = px + x[i];
    ppy = py + y[i];
    if(valido(ppx,ppy))
      if(mapa[ppx][ppy] < mapa[px][py])
	if(mapa[ppx][ppy] < menor){
	  menor = mapa[ppx][ppy];
	  prox = i;
	}
  }
  
  if(prox!=-1){    
    ppx = px + x[prox];
    ppy = py + y[prox];
    DFS(ppx,ppy);
    sink[px][py] = sink[ppx][ppy];
  }
  else sink[px][py] = k++;
  return;
}

int main(){
  int t,nt;
  int i,j;
  scanf("%d",&nt);
  for(t=1;t<=nt;t++){
    scanf("%d %d",&h,&w);
    for(i=0;i<h;i++)
      for(j=0;j<w;j++){
	scanf("%d",&mapa[i][j]);
	sink[i][j] = -1;
      }
    
    k = 0;
    for(i=0;i<h;i++)
      for(j=0;j<w;j++)
	DFS(i,j);
    printf("Case #%d:\n",t);
    for(i=0;i<h;i++){
      printf("%c",sink[i][0] + 'a');
      for(j=1;j<w;j++) printf(" %c",sink[i][j] + 'a');
      printf("\n");
    }
  }
  return 0;
}
