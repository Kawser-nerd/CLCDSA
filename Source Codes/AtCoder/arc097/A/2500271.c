#include<stdio.h>
#include<string.h>
int main(){
  char s[5010],c[10],d[5][5010]={{255,0},{255,0},{255,0},{255,0},{255,0}};
  int i,j,k,m;
  scanf("%s %d",s,&m);
  for(i=0;s[i];i++){
    for(j=0;j<5;j++){
      c[j]=s[i+j];
      c[j+1]=0;
      for(k=0;k<5;k++){
	if(strcmp(d[k],c)==0)goto NEXT;
      }//printf("not\n");
      for(k=5;k&&strcmp(d[k-1],c)>0;k--)strcpy(d[k],d[k-1]);
      strcpy(d[k],c);
    NEXT:;
      //for(k=0;k<5;k++)printf("%s ",d[k]);printf("\n");
    }
  }
  printf("%s\n",d[m-1]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s %d",s,&m);
   ^