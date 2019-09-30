//#include "pch.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define ll long long
#define fr(i,l,r) for(i=(l);i<(r);i++)
#define min(p,q) ((p)<(q)?(p):(q))
#define max(p,q) ((p)>(q)?(p):(q))
#define INF 1000000000000//10^12


int main(void)
{
	//?????
	int n;
	char s[60][60];
	int strtemp[30];
	int strans[30];

	//??????
	int i,j,k,l;
	int flag=0;
	int ans=0;
	int count=0;
	int temp,temp1,temp2;
	int max,min;
	int len;
	int sum=0;
	
	
	//????????
	scanf("%d",&n);
//	scanf_s("%d",&n);

	for(i=0;i<n;i++){
		scanf("%s",&s[i]);
//		scanf_s("\n%s",&s[i],60);	
//		printf("s[%d]=%s",i,s[i]);
	}

	for(i=0;i<30;i++){
		strtemp[i]=0;
		strans[i]=0;
	}

	//	printf("n?%d??\n", n);
	//	printf("??????????\n");
	//?????
	
	for(i=0;i<n;i++){
		len=strlen(s[i]);
		for(j=0;j<len;j++){
//			printf("s[i][j]=%d",s[i][j]);
			strtemp[s[i][j]-97]++;
		}
		for(j=0;j<26;j++){
//			printf("%c=%d",'a'+j,strtemp[j]);
			if(i==0) strans[j]=strtemp[j];
			strans[j]=min(strans[j],strtemp[j]);
			strtemp[j]=0;
		}
//		printf("\n");
	}
	


	//	printf("??????\n");
	
	//??
	
	for(i=0;i<26;i++){
//		printf("%c=%d",'a'+i,strans[i]);
		for(j=0;j<strans[i];j++){
			printf("%c",i+97);
		}
	}


	//	printf("???????\n");

	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:39:9: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[60]’ [-Wformat=]
   scanf("%s",&s[i]);
         ^
./Main.c:35:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:39:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",&s[i]);
   ^