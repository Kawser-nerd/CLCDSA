#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
struct node{
	int val;
	int index;
	int b;
}a[200000];
bool comp1(node a,node b){
	return a.val < b.val;
}
bool comp2(node a,node b){
	return a.index < b.index;
}
int main(){
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++){
		scanf("%d",&a[i].val);
		a[i].index = i;
	}
	sort(a+1,a+n+1,comp1);
	for(int i = 1;i <= n;i ++){
		a[i].b = i;
	}
	sort(a+1,a+n,comp2);
	int cnt[2] = {0,0};
	for(int i = 1;i <= n;i ++){
		if((a[i].index & 1) == (a[i].b & 1)){
			continue;
		}
		else {
			cnt[(a[i].index & 1)] ++;
		}
	}
	printf("%d",max(cnt[0],cnt[1]));
	return 0;
}