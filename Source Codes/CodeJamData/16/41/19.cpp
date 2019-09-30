#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int len,n,num[3],A[2000];
const char C[3]={'R','P','S'};
string ans[30][3];
int main(){
	freopen("Al.in","r",stdin);
	freopen("Al.out","w",stdout);
	int t; scanf("%d",&t);
	ans[0][0]+=C[0]; ans[0][1]+=C[1]; ans[0][2]+=C[2];
	for (int i=1;i<=20;i++)
		for (int j=0;j<3;j++)
			ans[i][j]=min(ans[i-1][j]+ans[i-1][(j+2)%3],ans[i-1][(j+2)%3]+ans[i-1][j]);
	for (int tt=1;tt<=t;tt++){
		scanf("%d%d%d%d",&n,&num[0],&num[1],&num[2]);
		string an="Z"; memset(A,0x00,sizeof A);
		for (int i=0;i<3;i++){
			int x[3]; memset(x,0x00,sizeof x);
			for (int j=0;j<(1<<n);j++) if (ans[n][i][j]=='R') x[0]++; else if (ans[n][i][j]=='P') x[1]++; else x[2]++;
			int flag=0;
			for (int j=0;j<3;j++) if (x[j]==num[j]) flag++;
			if (flag==3) an=min(an,ans[n][i]);
		}
		printf("Case #%d: ",tt);
		if (an=="Z") printf("IMPOSSIBLE\n");
		else cout<<an<<endl;
	}
}
