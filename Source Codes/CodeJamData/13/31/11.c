#include <stdio.h>
#include <string.h>
int n,t;
int d[1000010],pos[1000010];
char c[1000010];
int c_l;
int main(){
	freopen("A-large.in","r",stdin);
	freopen("A.out","w",stdout);
	int i,j;
	long long ans;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%s",c);
		scanf("%d",&n);
		ans = 0;
		memset(d,0,sizeof(d));
		memset(pos,-1,sizeof(pos));
		c_l = strlen(c);
		if(c[0]!='a' && c[0]!='e' && c[0]!='i' && c[0]!='o' && c[0]!='u'){
			d[0] = 1;
		}
		if(d[0] >= n){
			pos[0] = 0;
		}
		for(j=1;j<c_l;j++){
			if(c[j]!='a' && c[j]!='e' && c[j]!='i' && c[j]!='o' && c[j]!='u'){
				d[j] = d[j-1]+1;
			}
			else{
				d[j] = 0;
			}
			if(d[j] >= n){
				pos[j] = j-n+1;
			}
			else{
				pos[j] = pos[j-1];
			}
		}
		for(j=0;j<c_l;j++){
			ans += pos[j]+1;
		}
		printf("Case #%d: %lld\n",i+1,ans);
	}
	return 0;
}
