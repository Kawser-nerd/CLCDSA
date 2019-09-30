#include<stdio.h>
#include<stdlib.h>
#define ll long long

#define rep(i,l,r)for(ll i=(l);i<(r);i++)

ll d[110][110];
int main(){
	int h,w,n;
	scanf("%d%d%d",&h,&w,&n);
	ll s=0;
	rep(i,1,n+1){
		int t;
		scanf("%d",&t);
		while(t--){
			d[s/w][s%w]=i;
			s++;
		}
	}
	rep(i,0,h)rep(j,0,w){
		if(i%2==0)printf("%d%c",d[i][j],j==w-1?'\n':' ');
		else printf("%d%c",d[i][w-1-j],j==w-1?'\n':' ');
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:20: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long int’ [-Wformat=]
   if(i%2==0)printf("%d%c",d[i][j],j==w-1?'\n':' ');
                    ^
./Main.c:22:15: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long int’ [-Wformat=]
   else printf("%d%c",d[i][w-1-j],j==w-1?'\n':' ');
               ^
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&h,&w,&n);
  ^
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&t);
   ^