#include <stdio.h>
#include <string.h>
int main()
{
  char S[1000];
  scanf("%s",S);
  int nCnt=0,sCnt=0,eCnt=0,wCnt=0;
  int i=0;
  for(i=0;i<strlen(S);i++){
	  if(S[i]=='N')++nCnt;
	  else if(S[i]=='S')++sCnt;
	  else if(S[i]=='E')++eCnt;
	  else if(S[i]=='W')++wCnt;

  }

  if(nCnt>0 && sCnt>0 && eCnt>0 && wCnt>0) printf("Yes\n");
  else if(nCnt>0 && sCnt>0 && eCnt==0 && wCnt==0) printf("Yes\n");
  else if(nCnt==0 && sCnt==0 && eCnt>0 && wCnt>0) printf("Yes\n");
  else printf("No\n");
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",S);
   ^