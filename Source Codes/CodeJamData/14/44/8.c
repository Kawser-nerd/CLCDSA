#include<stdio.h>
#include<string.h>
struct xd{
	char s[10][15];
	int n;
}server[5];
int Max,way;
void find_ans(int now,int m,int n,char s[10][15]){
	int i,j;
	if(now==m){
		int all=0;
		for(i=0;i<n;i++){
			if(server[i].n==0)break;
			int nn=0,ii,jj,k,l;
			char node[1000][15]={};
			for(j=0;j<server[i].n;j++){
				l=strlen(server[i].s[j]);
				for(k=1;k<=l;k++){
					char tmp[15];
					strncpy(tmp,server[i].s[j],k);
					tmp[k]='\0';
					for(ii=0;ii<nn;ii++){
						if(strcmp(node[ii],tmp)==0)break;
					}
					if(ii==nn){
						strcpy(node[nn],tmp);
						nn++;
					}
				}
			}
			all+=(nn+1);
		}
		if(i==n){
			if(all==10){
			}
			if(all>Max){
				Max=all;
				way=1;
			}
			else if(all==Max)way++;
		}
	}
	else{
		for(i=0;i<n;i++){
			strcpy(server[i].s[server[i].n],s[now]);
			server[i].n++;
			find_ans(now+1,m,n,s);
			server[i].n--;
		}
	}
}
int main(){
	int T,I;
	scanf("%d",&T);
	for(I=0;I<T;I++){
		int i,j,m,n;
		char s[10][15];
		scanf("%d %d",&m,&n);
		Max=-1;
		way=0;
		for(i=0;i<m;i++){
			scanf("%s",s[i]);
		}
		for(i=0;i<n;i++)server[i].n=0;
		find_ans(0,m,n,s);
		printf("Case #%d: %d %d\n",I+1,Max,way);
	}
	return 0;
}