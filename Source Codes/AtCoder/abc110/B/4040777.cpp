#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int res,n,m,x,y,a[105],b[105];
int main(){
	int maxa = -999,minb = 999;
	scanf("%d %d %d %d",&n,&m,&x,&y);
	for(int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
		if(a[i] > maxa)	maxa = a[i];
	}
	for(int i = 1; i <= m; i++){
		scanf("%d",&b[i]);
		if(b[i] < minb)	minb = b[i];
	}
	
	for(int i = x + 1; i <= y; i++)
		if(i > maxa && minb >= i)
			res = 1; 

	res ? printf("No War") : printf("War");
}