#include<stdio.h>
char g[8][8];
int g2[8];
char tmp[101];
char map[256];
int amask,acount[8];
char a[101];
const char e[9]="QWERASDF";
int main(){
	int t;
	scanf("%d",&t);
	int i;
	memset(map,255,sizeof(map));
	for(i=0;i<8;i++)map[e[i]]=i;
	int pp;
	for(pp=1;pp<=t;pp++){
		int n;
		scanf("%d",&n);
		memset(g,0,sizeof(g));
		memset(g2,0,sizeof(g2));
		for(i=0;i<n;i++){
			scanf("%s",tmp);
			g[map[tmp[0]]][map[tmp[1]]]=tmp[2];
			g[map[tmp[1]]][map[tmp[0]]]=tmp[2];
		}
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%s",tmp);
			g2[map[tmp[0]]]|=(1<<map[tmp[1]]);
			g2[map[tmp[1]]]|=(1<<map[tmp[0]]);
		}
		scanf("%d",&n);
		scanf("%s",tmp);
		int len=0;
		amask=0;
		memset(acount,0,sizeof acount);
		for(i=0;i<n;i++){
			if(len>0 && map[a[len-1]]>=0 && g[map[tmp[i]]][map[a[len-1]]]){
				acount[map[a[len-1]]]--;
				if(acount[map[a[len-1]]]<=0)amask-=(1<<map[a[len-1]]);
				a[len-1]=g[map[tmp[i]]][map[a[len-1]]];
			}else if(g2[map[tmp[i]]]&amask){
				amask=0;
				len=0;
				memset(acount,0,sizeof acount);
			}else {
				a[len++]=tmp[i];
				amask|=(1<<map[tmp[i]]);
				acount[map[tmp[i]]]++;
			}
		}
		a[len]=0;
		printf("Case #%d: [",pp);
		if(len)printf("%c",a[0]);
		for(i=1;i<len;i++)printf(", %c",a[i]);
		printf("]\n");
	}
	return 0;
}
