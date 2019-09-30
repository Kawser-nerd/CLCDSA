#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,A[30],a[30];
int compare(int k1,int k2){
	return A[k1]<A[k2];
}
int main(){
	freopen("Al.in","r",stdin);
	freopen("Al.out","w",stdout);
	int t; scanf("%d",&t);
	for (int k=1;k<=t;k++){
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&A[i]);
		printf("Case #%d: ",k);
		for (int i=1;i<=n;i++) a[i]=i;
		sort(a+1,a+n+1,compare);
		while (A[a[n]]!=A[a[n-1]]){
			A[a[n]]--; putchar('A'+a[n]-1); putchar(' ');
		}
		for (int i=1;i<=n-2;i++)
			while (A[a[i]]){
				A[a[i]]--; putchar('A'+a[i]-1); putchar(' ');
			}
		while (A[a[n]]){
			A[a[n]]--; putchar('A'+a[n]-1); putchar('A'+a[n-1]-1); putchar(' ');
		}
		putchar('\n');
	}
	return 0;
}

	
	
