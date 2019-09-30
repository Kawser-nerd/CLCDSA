#include <stdio.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)

char s[600][600];
ll h,w;
int main(){
	scanf("%lld%lld\n",&h,&w);
	rep(i,0,h)scanf("%s",s+i);

	rep(i,0,h){
		rep(j,0,w)putchar(j==0||(i%2==0&&j!=w-1)||s[i][j]=='#'?'#':'.');
		putchar('\n');
	}
	putchar('\n');
	rep(i,0,h){
		rep(j,0,w)putchar(j==w-1||(i%2==1&&j!=0)||s[i][j]=='#'?'#':'.');
		putchar('\n');
	}
} ./Main.c: In function ‘main’:
./Main.c:9:18: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[600]’ [-Wformat=]
  rep(i,0,h)scanf("%s",s+i);
                  ^
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld\n",&h,&w);
  ^
./Main.c:9:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,h)scanf("%s",s+i);
            ^