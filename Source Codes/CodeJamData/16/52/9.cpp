#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int tcn,tc;
int n,m;
char s[110];
int a[110];
char ptn[10][30];
int ptnl[10];
const int montecarlo=20000;
int match[10];
char d[110];
int chk[110];
int main(){
	int i,j,k,tryn;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&tcn);
	for(tc=1;tc<=tcn;tc++){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			a[i]--;
		}
		scanf("%s",s);
		scanf("%d",&m);
		for(i=0;i<m;i++){
			scanf("%s",ptn[i]);
			ptnl[i]=strlen(ptn[i]);
		}
		for(i=0;i<m;i++){
			match[i]=0;
		}
		for(tryn=0;tryn<montecarlo;tryn++){
			for(i=0;i<n;i++){
				chk[i]=0;
			}
			for(j=0;j<n;j++){
				while(1){
					i=rand()%n;
					if(chk[i]==0){
						break;
					}
				}
				while(a[i]!=-1&&chk[a[i]]!=1){
					i=a[i];
				}
				chk[i]=1;
				d[j]=s[i];
			}
			d[n]=0;
			for(i=0;i<m;i++){
				for(j=0;j<n;j++){
					for(k=0;k<ptnl[i];k++){
						if(ptn[i][k]!=d[j+k])break;
					}
					if(k==ptnl[i]){
						match[i]++;
						break;
					}
				}
			}
		}
		printf("Case #%d:",tc);
		for(i=0;i<m;i++){
			printf(" %.5lf",1.0*match[i]/montecarlo);
		}
		printf("\n");
	}
	return 0;
}