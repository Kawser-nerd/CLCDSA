#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE_S (521196)
#define MIN(u,v) (((u)<(v))?(u):(v))
#define MAX(u,v) (((u)>(v))?(u):(v))
char s[SIZE_S][11];
int dp[52][5];

int comp(const void *_p,const void *_q){
	char *p=(char *)_p,*q=(char *)_q;
	int __p=strlen(p),__q=strlen(q);
	if(__p!=__q)return __p-__q;
	else return strcmp(p,q);
}

int main(){
	FILE *fp;
	int i,j,l,m,k,t,tmp,tmp2,f;
	char x[52];
	fp=fopen("garbled_email_dictionary.txt","r");
	for(i=0;i<SIZE_S;i++){
		fscanf(fp,"%s",s[i]);
	}
	fclose(fp);
	qsort(s,SIZE_S,11,comp);
	scanf("%d",&t);
	for(k=1;k<=t;k++){
		scanf("%s",x+1);
		for(i=0;i<=strlen(x+1);i++)for(j=0;j<5;j++)dp[i][j]=SIZE_S;
		dp[0][4]=0;
		for(i=1;i<=strlen(x+1);i++){
			for(j=0;j<5;j++){
				for(l=0;l<SIZE_S;l++){
					if(strlen(s[l])>i)break;
					tmp=j;tmp2=dp[i-strlen(s[l])][j];f=0;
					for(m=0;m<strlen(s[l]);m++){
						if(s[l][m]==x[i-strlen(s[l])+m+1])tmp=MIN(tmp+1,4);
						else{
							if(tmp<4){f=1;break;}
							else{tmp=0;tmp2++;}
						}
					}
					if(f)continue;
					dp[i][tmp]=MIN(dp[i][tmp],tmp2);
				}
			}
		}
		tmp=SIZE_S;
		for(i=0;i<5;i++)tmp=MIN(tmp,dp[strlen(x+1)][i]);
		printf("Case #%d: %d\n",k,tmp);
	}
	return 0;
}
