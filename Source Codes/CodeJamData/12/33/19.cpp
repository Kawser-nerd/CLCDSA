#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;


long long a[110];//num of box
long long A[110];//box type
long long b[110];//num of toy
long long B[110];//toy type;

long long dp[110][110];

int main() {
	long long  i,j,k,m,n,v,sum;
	int tc, cn(0);
	
	freopen("C-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	cin>>tc;
	while(tc--) {
		cin>>m>>n;
		a[0]=A[0]=b[0]=B[0]=0;
		for(i=1;i<=m;i++)
			cin>>a[i]>>A[i];
		for(i=1;i<=n;i++)
			cin>>b[i]>>B[i];
			
		memset(dp,0,sizeof(dp));
			
		for(i=1;i<=m;i++) {
			for(j=1;j<=n;j++) {
				if(A[i]!=B[j]) {
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			 	} else {
					int tmp=A[i];
					long long X,Y,x,y;
					x=i;
					y=j;
					X=a[x];
					Y=b[y];
				//	cout<<i<<" "<<j<<"---"<<endl;
					while(1) {
						//cout<<x<<" "<<y<<" "<<X<<" "<<Y<<endl;
						if(x==0||y==0)
						break;
						
						if(X==Y) {
							dp[i][j]=max(dp[i][j],dp[x-1][y-1]+X);
							break;
						}
						if(X>Y) {
							dp[i][j]=max(dp[i][j],dp[x-1][y-1]+Y);
							y--;
							if(B[y]==tmp)
							Y+=b[y];
						} else {
							dp[i][j]=max(dp[i][j],dp[x-1][y-1]+X);
							x--;
							if(A[x]==tmp)
							X+=a[x];
						}
					}
				}				
			}
		}
		cout<<"Case #"<<++cn<<": ";
		cout<<dp[m][n]<<endl;		
	}
	return 0;
}