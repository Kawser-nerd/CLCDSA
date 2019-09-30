#include<stdio.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
int n,m;
char s[120][120];
inline bool cheh(int x){
	fo(i,1,m) if (s[x][i]=='#') return 0;
	return 1;
}
inline void delh(int x){
	fo(i,x,n-1) fo(j,1,m) s[i][j]=s[i+1][j];
	n--;
}
inline bool chel(int x){
	fo(i,1,n) if (s[i][x]=='#') return 0;
	return 1;
}
inline void dell(int x){
	fo(j,x,m-1) fo(i,1,n) s[i][j]=s[i][j+1];
	m--;
}
int main(){
	scanf("%d%d",&n,&m);
	fo(i,1,n) scanf("%s",s[i]+1);
	while (1){
		bool ok=0;
		fo(i,1,n) if (cheh(i)){
			delh(i);
			ok=1;//continue;//null
			//break;//
		}
		fo(i,1,m) if (chel(i)){
			dell(i);
			ok=1;//continue;//null
			//break;//
		}
		if (!ok) break;
	}
	//printf("%d %d\n",n,m);
	fo(i,1,n){
		fo(j,1,m) putchar(s[i][j]);
		putchar('\n');
	}
	return 0;
}