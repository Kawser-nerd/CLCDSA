#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,c,k;
int t[200000];
int main(){
	scanf("%d%d%d",&n,&c,&k);
	for(int i = 0;i < n;i++){
		scanf("%d",&t[i]);
	}
	sort(t,t+n);
	int pre = -1;
	int cnt = 0;
	int ans = 0;
	for(int i = 0;i < n;i++){
		if(pre == -1){
			pre = t[i];
			ans++;
			cnt++;
		}
		else{
			if(t[i] - pre > k){
				pre = -1;
				cnt = 0;
				i--;
			}
			else if(cnt >= c){
				pre = -1;
				cnt = 0;
				i--;
			}
			else{
				cnt ++;
			}
		}
	}
	printf("%d",ans);
	return 0;
}