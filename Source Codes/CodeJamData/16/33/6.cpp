#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a,b,c,ans[2000][3],K,num[20][20],pd[20],len;
long long m;
int main(){
	freopen("Cl.in","r",stdin);
	freopen("Cl.out","w",stdout);
	int t; scanf("%d",&t);
	for (int k=1;k<=t;k++){
		scanf("%d%d%d%d",&a,&b,&c,&K);
		printf("Case #%d: ",k); len=0;
		memset(num,0x00,sizeof num);
		for (int i=1;i<=a;i++){
			memset(pd,0x00,sizeof pd);
			for (int j=1;j<=b;j++){
				for (int k=1;k<=min(K,c);k++){
					len++; ans[len][0]=i; ans[len][1]=j; ans[len][2]=(i+j+k-1)%c+1;
				}
			}
		}
		printf("%d\n",len);
		for (int i=1;i<=len;i++) printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
	}
	return 0;
}

	
	
