#include<cstdio>
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

long long trans(string t){
	long long d =0;
	for(int i = 0; i< t.size();i++){
		d =d*2;
		d += t[i]-'0';
	}
	return d;
}
string ans;
bool square(long long y){
	long long t= sqrt(y);

	if(t*t == y)return true;
	return false;
}
long long  search(string s, int t){
	if(t == s.size()){
		long long d = trans(s);
//		cout << s << endl;
		if(square(d)){
			ans=s;
			return d;
		}
		else {
			return -1;
		}
	}
	if(s[t] == '0' || s[t] == '1')return search(s, t+1);
	else{
		s[t] = '0';
		long long  d = search(s, t+1);
		if(d < 0){
			s[t] = '1';
			d = search(s, t+1);
		}
		return d;
	}
}


void work(int x)
{

	printf("Case #%d: ",x);
	string s;
	cin >> s;
	search(s, 0);
	cout << ans << endl;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i = 1; i <= t; i++)work(i);
}
