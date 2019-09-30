#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 512

int PD[TAM][TAM];
char line[TAM];
char code[TAM];

int main(){
  int i,j,m,n;
  int t,nt;
  strcpy(code,"welcome to code jam");
  n = strlen(code);
  scanf("%d",&nt);
  for(t=1;t<=nt;t++){
    scanf(" %[^\r\n]",line);
    memset(PD,0,sizeof(PD));
    m = strlen(line);
    
    PD[0][0] = line[0] == 'w';
    for(j=1;j<m;j++){
      if(line[j] == 'w') PD[0][j] = PD[0][j-1]+1;
      else PD[0][j] = PD[0][j-1];
    }
    
    for(i=1;i<n;i++){
      PD[i][0] = 0;
      for(j=1;j<m;j++){
	PD[i][j] = PD[i][j-1];
	if(code[i] == line[j]) PD[i][j] = (PD[i][j] +  PD[i-1][j-1])%10000;	
      }
    }
    printf("Case #%d: %04d\n",t,PD[18][m-1]);

  }
  return 0;

}
	
	
      
