#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TAM 500001
#define LIM 1001

int  PD[11][TAM];

int happynumber(int num,int base){
  int soma,aux,passos;
  int flag = num == 91;
  passos = 0;
  while(num!=1 && passos < LIM){
    soma = 0;
    aux = num;
    while(aux!=0){
      soma = soma + ((aux%base)*(aux%base));
      aux/=base;
    }   
    num = soma;
    if(PD[base][num] == 1){
      return 1;
    }
    if(PD[base][num] == 0) return 0;
    passos++;
  }
  
  if(num == 1) return 1;
  else return 0;

}

int main(){
  int i,j;
  int nt,t;
  int achou;
  int n,base[LIM];
  char entrada[TAM];
  int m;
  memset(PD,-1,sizeof(PD));
  
  for(i=2;i<TAM;i++)
    for(j=2;j<=10;j++)
      PD[j][i] = happynumber(i,j);
	
  scanf("%d",&nt);  
  
  for(t=1;t<=nt;t++){
    scanf(" %[^\n]s",entrada);
    m = strlen(entrada);
    n = 0;
    for(i=0;i<m;i+=2){
      if(i+1<m && entrada[i]=='1' && entrada[i+1]=='0') base[n++] = 10;
      else base[n++] = entrada[i]-'0';
    }     
      
    for(i=2;i<TAM;i++){
      achou = 1;
      for(j=0;j<n;j++)
	if(!PD[base[j]][i]){	 
	  achou = 0;
	  break;
	}
      if(achou)	break;
      
    }
    /* printf("<< %d %d >> \n",PD[9][91],PD[10][91]);*/
    printf("Case #%d: %d\n",t,i);
  }
  return 0;
}
