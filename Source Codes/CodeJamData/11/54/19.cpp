#include <cstdio>
#include <cmath>
#include <cstring>
#include <memory.h>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
const __int64 maxl=101;
char str[maxl];
char ans[maxl];
__int64 len;
bool flag;

void init(){
	scanf("%s",str);
	return;
}

__int64 getvalue(){
	__int64 ans=0;
	for (__int64 i=0;i<len;i++){
		ans<<=1;
		ans+=str[i]-'0';
	}
	return ans;
}

void dfs(__int64 k){
	if (k==len){
		__int64 cur=getvalue();
		__int64 root=((__int64)sqrt((double)cur));
		if (root*root==cur){
			for (__int64 i=0;i<len;i++){
				ans[i]=str[i];
				flag=true;
			}
		}
		return;
	}
	if ((str[k]=='0')||(str[k]=='1')){
		dfs(k+1);
		return;
	}
	str[k]='0';
	dfs(k+1);
	if (flag){
		return;
	}
	str[k]='1';
	dfs(k+1);
	str[k]='?';
	return;
}

void calc(){
	len=strlen(str);
	flag=false;
	dfs(0);
	for (__int64 i=0;i<len;i++){
		printf("%c",ans[i]);
	}
	puts("");
	return;
}

int main(){
	__int64 tcase;
	scanf("%I64d",&tcase);
	for (__int64 i=1;i<=tcase;i++){
		init();
		printf("Case #%I64d: ",i);
		calc();
	}
	return 0;
}
