#include <iostream>
#include <cstdio>
#include<string>
#include<cstring>
#include <algorithm>
#include <cmath>
#include <map>

#define N 100005

using namespace std;

int vis[N],a[N];
void sushu() {
	for(int i=2; i<=10005; i++) {
		if(!vis[i]) {
			for(int j=i*2; j<=N; j+=i)
				vis[j]=1;
		}
	}
}

int main() {
	memset(vis,0,sizeof(vis));
	sushu();
	vis[1]=1;
	int sum=0,n;
	for(int i=1; i<=N; i++) {
		if(i%2==1) {
			if(vis[i]==0&&vis[(i+1)/2]==0)
				sum++;
		}
		a[i]=sum;
	}
	scanf("%d",&n);

	while(n--) {
		int c,b;
		scanf("%d%d",&c,&b);
		printf("%d\n",a[b]-a[c-1]);
	}

}