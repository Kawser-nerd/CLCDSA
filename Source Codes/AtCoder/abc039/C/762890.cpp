#define _CRT_SECURE_NO_WARNINGS
#include<sstream>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<numeric>
#include<functional>
#include<algorithm>
#include<bitset>
#include<tuple>
#include<unordered_set>
#include<random>
using namespace std;
#define INF (1<<29)
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(all(v)),v.end())


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string k = "WBWBWWBWBWBW";
	k += k+k;

	string oto[12] = { "Do","Do","Re","Re","Mi","Fa","Fa","So","So","La","La","Si" };

	string s;
	cin >> s;
	rep(i, 12) {
		if (k.substr(i, 20) == s) {
			cout << oto[i] << endl;
			break;
		}
	}


	return 0;
}