#include<stdio.h>

char nextChar();

char N, K, i, j;
char T[5][5];

char pon(char n, char t){
  if(n==N){
    if(t==0){return 1;}
    else{return 0;}
  }
  char k;
  for(k=0; k<K; k++){
    if(pon(n+1, t^T[n][k])){return 1;}
  }
  return 0;
}

int main(){
  N=nextChar();
  K=nextChar();
  for(i=0; i<N; i++){
    for(j=0; j<K; j++){
      T[i][j]=nextChar();
    }
  }
  if(pon(0, 0)){
    printf("Found\n");
  }else{
    printf("Nothing\n");
  }
	return 0;
}

char nextChar(){
	char f=0; char c=getchar();
	while((c<'0')||('9'<c)){c=getchar();}
	while((c>='0')&&(c<='9')){f=f*10+(c-'0'); c=getchar();}
	return f;
}