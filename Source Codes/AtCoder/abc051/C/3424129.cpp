#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
int cntDiv(int n){
	int ans = 0;
	for (int i= 1;i*i<=n;i+=2){
		if(n%i==0){
			if(i*i==n)ans++;
			else ans +=2;
		}
	}
	return ans;
}
string makeStr(char c,int num){
	string ans = "";
	REP(i,num){
		ans += c;
	}
	return ans;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int sx,sy,tx,ty,w,h;
	string ans = "";
	scanf("%d %d %d %d",&sx,&sy,&tx,&ty);
	w = tx - sx;
	h = ty - sy;
	ans += string(h,'U');
	ans += string(w,'R');
	ans += string(h,'D');
	ans += string(w,'L');
	ans += 'L';
	ans += string(h+1,'U');
	ans += string(w+1,'R');
	ans += "DR";
	ans += string(h+1,'D');
	ans += string(w+1,'L');
	ans += 'U';

	cout << ans << endl;
	return 0;
}