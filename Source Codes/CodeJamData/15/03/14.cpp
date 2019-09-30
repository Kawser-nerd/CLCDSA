#include <cstdio>
#include <cstring>
typedef long long ll;
int t,l;
int m[5][5],s[5][5];
ll x;
char str[10005];
int main(){
	memset(s,0,sizeof(s));
	for(int y=0;y<=3;y++) m[0][y]=m[y][0]=y;
	m[1][1]=m[2][2]=m[3][3]=0;
	s[1][1]=s[2][2]=s[3][3]=1;
	m[1][2]=m[2][1]=3;s[2][1]=1;
	m[2][3]=m[3][2]=1;s[3][2]=1;
	m[1][3]=m[3][1]=2;s[1][3]=1;
	scanf("%d\n",&t);
	for(int c=1;c<=t;c++){
		scanf("%d %lld\n%s\n",&l,&x,str);
		int mult=0,sign=0;
		for(int y=0;y<l;y++){
			sign^=s[mult][str[y]-'h'];
			mult=m[mult][str[y]-'h'];
		}
		if(mult==0&&sign==0||mult==0&&sign==1&&(x%2ll==0ll)||mult&&(x%4ll!=2ll)){
			printf("Case #%d: NO\n",c);
			continue;
		}
		bool done=0;
		mult=0,sign=0;
		int start=0,finish=0;
		for(int z=0;z<4;z++){
			for(int y=0;y<l;y++){
				sign^=s[mult][str[y]-'h'];
				mult=m[mult][str[y]-'h'];
				start++;
				if(mult==1&&sign==0){done=1;break;}
			}
			if(done)break;
		}
		if(!done){
			printf("Case #%d: NO\n",c);
			continue;
		}
		done=0;
		mult=0,sign=0;
		for(int z=0;z<4;z++){
			for(int y=l-1;y>=0;y--){
				sign^=s[str[y]-'h'][mult];
				mult=m[str[y]-'h'][mult];
				finish++;
				if(mult==3&&sign==0){done=1;break;}
			}
			if(done)break;
		}
		if(!done){
			printf("Case #%d: NO\n",c);
			continue;
		}
		if(ll(start+finish)<ll(l)*x) printf("Case #%d: YES\n",c);
		else printf("Case #%d: NO\n",c);
	}
	return 0;
}
