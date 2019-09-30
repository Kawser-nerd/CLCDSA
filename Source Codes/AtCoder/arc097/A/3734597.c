#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define llong long long
#define fr(i,l,r) for(i=(l);i<(r);i++)
#define min(p,q) ((p)<(q)?(p):(q))
#define max(p,q) ((p)>(q)?(p):(q))
#define INF 1000000000000//10^12

int main(void)
{
	//?????
	char s[5010];
	char anschar[10];
	int sint[5010];
	int n,m;
	static int map1[30];
	static int map2[30][30];
	static int map3[30][30][30];
	static int map4[30][30][30][30];
	static int map5[30][30][30][30][30];
	
	//??????
	int i,j,k,l,p;
	int flag=0;
	llong int ans=0;
	int count=0;
	int temp,temp1,temp2;
	llong int max,min;
	int len;
	int sum=0;
	//????????
	scanf("%s",&s);
	scanf("%d",&m);
	
	
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	n=strlen(s);
	
	for(i=0;i<n;i++){
		sint[i]=s[i]-'a';
	}
	for(i=0;i<n;i++){
		map1[sint[i]]++;
		if(i<n-1)map2[sint[i]][sint[i+1]]++;
		if(i<n-2)map3[sint[i]][sint[i+1]][sint[i+2]]++;
		if(i<n-3)map4[sint[i]][sint[i+1]][sint[i+2]][sint[i+3]]++;
		if(i<n-4)map5[sint[i]][sint[i+1]][sint[i+2]][sint[i+3]][sint[i+4]]++;
	}
	
	for(i=0;i<26;i++){
		if(map1[i]>0){
			count++;
			if(count==m){
				printf("%c",i+'a');
			}
		}
		for(j=0;j<26;j++){
			if(map2[i][j]>0){
				count++;
				if(count==m){
					printf("%c%c",i+'a',j+'a');
				}
			}
			for(k=0;k<26;k++){
				if(map3[i][j][k]>0){
					count++;
					if(count==m){
						printf("%c%c%c",i+'a',j+'a',k+'a');
					}
				}
				for(l=0;l<26;l++){
					if(map4[i][j][k][l]>0){
						count++;
						if(count==m){
							printf("%c%c%c%c",i+'a',j+'a',k+'a',l+'a');
						}
					}
					for(p=0;p<26;p++){
						if(map5[i][j][k][l][p]>0){
							count++;
							if(count==m){
								printf("%c%c%c%c%c",i+'a',j+'a',k+'a',l+'a',p+'a');
							}
						}
					}
				}
			}
		}
	}
	
//	printf("??????\n");
	//??
	
	//printf("%lld",ans);
	
//	printf("???????\n");
	
	return 0;
	
} ./Main.c: In function ‘main’:
./Main.c:35:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[5010]’ [-Wformat=]
  scanf("%s",&s);
        ^
./Main.c:35:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",&s);
  ^
./Main.c:36:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&m);
  ^