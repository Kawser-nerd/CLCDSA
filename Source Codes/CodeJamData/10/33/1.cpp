#include<iostream>
#define minx(a,b) (a<b?a:b)
using namespace std;

int in[513][513],use[513][513],dp[513][513],maxn,stx,sty,anum;

int main(){
	freopen("C-large.in","r",stdin);
	freopen("pc.txt","w",stdout);
	int t,m,n,tt,i,j,k,w,ansx[1000];
	int ch[300];
	char c;
	memset(ch,0,sizeof(ch));
	for(i=0 ; i<10 ; i++) ch[i+48]=i;
	for(i='A' ; i<='F' ; i++) ch[i]=i-'A'+10;
	scanf("%d",&tt);
	for(t=1 ; t<=tt ; t++){
		memset(in,0,sizeof(in));
		scanf("%d%d",&m,&n);
		for(i=0 ; i<m ; i++){
			for(j=0 ; j<n ; j+=4){
				cin >> c;
				w=ch[c];
				for(k=j+3 ; k>=j ; k--){
					in[i][k]=w%2;
					w/=2;
				}
			}
		}
		memset(ansx,0,sizeof(ansx));
		memset(use,0,sizeof(use));
		maxn=1;
		while(maxn){
			memset(dp,0,sizeof(dp));
			maxn=0;
			for(i=1 ; i<m ; i++){
				for(j=1; j<n ; j++){
					if(in[i][j]==in[i-1][j-1] && in[i][j]!=in[i-1][j] && in[i][j]!=in[i][j-1] && !use[i][j-1] && !use[i-1][j] && !use[i-1][j-1] && !use[i][j]) 
						dp[i][j]=minx(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
					if(dp[i][j]>maxn){
						maxn=dp[i][j];
						stx=i-maxn;
						sty=j-maxn;
					}
				}
			}
			if(maxn){
				maxn++;
				for(i=stx ; i<stx+maxn ; i++){
					for(j=sty ; j<sty+maxn ; j++){
						use[i][j]=true;
					}
				}
				ansx[maxn]++;
			}
		}
		for(i=0 ; i<m ; i++){
			for(j=0 ; j<n ; j++){
				if(!use[i][j]) ansx[1]++;
			}
		}
		anum=0;
		for(i=555 ; i>=0 ; i--){
			if(ansx[i]) anum++;
		}
		cout << "Case #" << t << ": " << anum << endl;
		for(i=555 ; i>=0 ; i--){
			if(ansx[i]) cout << i << ' ' << ansx[i] << endl;
		}
	}
}
