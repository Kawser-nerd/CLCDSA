//#include "pch.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

//#include <vector>
//#include <set>
//#include <map>
//#include <iostream>

#define ll long long
#define fri(n) for(i=0;i<(n);i++)
#define frj(n) for(j=0;j<(n);i++)
#define min(p,q) ((p)<(q)?(p):(q))
#define max(p,q) ((p)>(q)?(p):(q))
#define swap(p,q) r=(p);(p)=(q);(q)=r
#define INF 1000000000000//10^12



int main(void)
{
	//?????
	int q;
	static char s[100010];
	static char t[100010];
	static int a[100010];
	static int b[100010];
	static int c[100010];
	static int d[100010];
	static int ruiseki_s[100010];
	static int ruiseki_t[100010];

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

	scanf("%s",&s);
	scanf("%s",&t);
//	scanf_s("%s",&s,100010);
//	scanf_s("%s",&t,100010);

	scanf("%d",&q);
//	scanf_s("%d",&q);

	for(i=0;i<q;i++){
		scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
//		scanf_s("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
	}

	//	printf("n?%d??\n", n);
	//	printf("??????????\n");
	//?????
	
	ruiseki_s[0]=0;
	len=strlen(s);
	for(i=0;i<len;i++){
		if(s[i]=='A'){
			ruiseki_s[i+1]=(ruiseki_s[i]+1)%3;
		}else{
			ruiseki_s[i+1]=(ruiseki_s[i]+2)%3;
		}
	}

	ruiseki_t[0]=0;
	len=strlen(t);
	for(i=0;i<len;i++){
		if(t[i]=='A'){
			ruiseki_t[i+1]=(ruiseki_t[i]+1)%3;
		}else{
			ruiseki_t[i+1]=(ruiseki_t[i]+2)%3;
		}
	}
	
	for(i=0;i<q;i++){
		temp1=ruiseki_s[b[i]]-ruiseki_s[a[i]-1];
		temp2=ruiseki_t[d[i]]-ruiseki_t[c[i]-1];
		if((temp1-temp2)%3==0){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}

	//	printf("??????\n");

	//??

	//printf("%d",ans);

	//	printf("???????\n");


	return 0;
} ./Main.c: In function ‘main’:
./Main.c:50:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[100010]’ [-Wformat=]
  scanf("%s",&s);
        ^
./Main.c:51:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[100010]’ [-Wformat=]
  scanf("%s",&t);
        ^
./Main.c:50:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",&s);
  ^
./Main.c:51:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",&t);
  ^
./Main.c:55:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&q);
  ^
./Main.c:59:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
   ^