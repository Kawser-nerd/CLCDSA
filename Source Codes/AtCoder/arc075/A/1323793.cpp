#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <string>
#include <stack>
#include <set>
#include <deque>
#define mp make_pair
using namespace std;
int n,s[105],ans,m=100000;
int main(){
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>s[i];
		ans+=s[i];
		if (s[i]%10!=0 && s[i]<m) m=s[i];
	}
	if (ans%10==0){
		if (m==100000){
			cout<<0;
		}else{
			cout<<ans-m;
		}
	}else{
		cout<<ans;
	}
	return 0;
}