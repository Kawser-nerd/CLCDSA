#include <stdio.h>
 
typedef long long ll;
 
int H,W;
ll T;
char s[15][15];
 
ll min(ll a,ll b){
	if(a<b){return a;}
	else{return b;}
}
ll max(ll a,ll b){
	if(a>b){return a;}
	else{return b;}
}
 
ll d[105][105];
 
void warshall_floyd(){
	int i,j,k;
 
	for(k=0;k<H*W;k++){
		for(i=0;i<H*W;i++){
			for(j=0;j<H*W;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
}
void init(ll x){
 
	int i,j;
 
	for(i=0;i<H*W;i++){
		for(j=0;j<H*W;j++){
			d[i][j]=1000000007ll;
			if(i==j){d[i][j]=0ll;}
		}
	}
 
	for(i=0;i<H;i++){
		for(j=0;j<W;j++){
			int pos=(i*W)+j;
			int pos1=(i*W)+j-1;
			int pos2=(i*W)+j+1;
			int pos3=((i+1)*W)+j;
			int pos4=((i-1)*W)+j;
 
			if(0<=pos1&&pos1<H*W && j>0){
				if(s[i][j]=='.'){
					d[pos1][pos]=1ll;
				}
				else{
					d[pos1][pos]=x;
				}
			}
			if(0<=pos2&&pos2<H*W && j<W-1){
				if(s[i][j]=='.'){
					d[pos2][pos]=1ll;
				}
				else{
					d[pos2][pos]=x;
				}
			}
			if(0<=pos3&&pos3<H*W){
				if(s[i][j]=='.'){
					d[pos3][pos]=1ll;
				}
				else{
					d[pos3][pos]=x;
				}
			}
			if(0<=pos4&&pos4<H*W){
				if(s[i][j]=='.'){
					d[pos4][pos]=1ll;
				}
				else{
					d[pos4][pos]=x;
				}
			}
		}
	}
}
 
int check(int from,int to){
	warshall_floyd();
	int i,j;
 
	if(d[from][to]<=T){return 0;}
	else{return 1;}
}
 
int main(){
 
 
	scanf("%d %d %lld",&H,&W,&T);
 
	int i,j;
 
	int start[2];
	int goal[2];
 
	for(i=0;i<H;i++){
		for(j=0;j<W;j++){
			scanf(" %c",&s[i][j]);
			if(s[i][j]=='S'){start[0]=i;start[1]=j;s[i][j]='.';}
			else if(s[i][j]=='G'){goal[0]=i;goal[1]=j;s[i][j]='.';}
		}
	}
	ll l=1ll;
	ll r=T;
	while(l+1ll<r){
		ll mid=(l+r)/2ll;
		init(mid);
		if(check((start[0]*W)+start[1],(goal[0]*W)+goal[1])==0){
		l=mid;
		}
		else{
		r=mid;
		}
	}
	printf("%lld\n",l);
 
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:97:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %lld",&H,&W,&T);
  ^
./Main.c:106:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf(" %c",&s[i][j]);
    ^