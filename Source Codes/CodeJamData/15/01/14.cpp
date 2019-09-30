#include <cstdio>
int t,k,y;
char str[1005];
int main(){
	scanf("%d\n",&t);
	for(int y=1;y<=t;y++){
		scanf("%d %s\n",&k,str);
		int cnt=0,ans=0;
		for(int x=0;x<=k;x++){
			int c=str[x]-'0';
			if(c&&x>cnt){
				ans=(x-cnt)>ans?x-cnt:ans;
			}
			cnt+=c;
		}
		printf("Case #%d: %d\n",y,ans);
	}
	return 0;
}
