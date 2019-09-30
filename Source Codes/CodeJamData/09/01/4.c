#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM 5001

int m;
int foi[TAM];
char word[TAM][TAM];
char duvida[TAM],letras[TAM];

int valido(char a){
  int i;
  for(i=0;i<m;i++)
    if(a == letras[i])
      return 1;
  return 0;
}

int main(){
  int i,j,k,p;
  int L,D,N;
  int tam,ans;
  scanf("%d %d %d",&L,&D,&N);
  for(i=0;i<D;i++) scanf(" %s",word[i]);
  for(i=1;i<=N;i++){
    scanf(" %s",duvida);
    tam = strlen(duvida);
    for(j=0;j<D;j++) foi[j] = 1;    
        
    p = 0;
    for(j=0;j<tam;j++,p++){
      if(duvida[j]!='('){
	letras[0] = duvida[j];
	m = 1;
      }
      else{
	j++;
	m = 0;
	while(j<tam && duvida[j]!=')')  letras[m++] = duvida[j++];
      }
   
      for(k=0;k<D;k++)
	if(!valido(word[k][p]))
	   foi[k] = 0;
    }
    ans = 0;
    for(j=0;j<D;j++)
      if(foi[j])
	ans++;
    printf("Case #%d: %d\n",i,ans);
  }
  return 0;
}
