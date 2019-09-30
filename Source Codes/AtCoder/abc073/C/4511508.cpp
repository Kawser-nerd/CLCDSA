#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<map>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

 

int main() {
	int n; 
	map<string, int>mp;
	scanf("%d", &n);
	getchar();
	string str;
	for (int i = 0; i < n; i++) {
		getline(cin, str);
		mp[str]++;
	}
	
	int cnt = 0;
	map<string, int>::iterator it;
	for (it = mp.begin(); it != mp.end(); it++) {
		if (it->second % 2 == 1) {
			cnt++;
			//printf("%s ", it->first);
			//cout << it->first << endl;;
		}
	}
	printf("%d\n", cnt);
	return 0;
}