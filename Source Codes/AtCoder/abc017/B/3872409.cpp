#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include<queue>
#include <sstream>
#include <set>
const int dx[8]={1,0,-1,0,1,-1,-1,1};
const int dy[8]={0,1,0,-1,1,1,-1,-1};
const int INF = 1e9;
#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define SORT(a) sort(a.begin(),a.end())
using namespace std;
int main(){
    string s;
    cin >> s;
	int size = s.size();
 
	s.push_back('x');
 
	for (int i = 0; i < size-1; i++) {
		if (s[i] == 'c'&&s[i+1] == 'h') { 
            i++; 
            continue; 
        }
		if (s[i] != 'o'&&s[i] != 'k'&&s[i] != 'u') { 
            cout << "NO" << endl;
            return 0;
        }
	}
	cout << "YES" << endl;
 
	return 0;
}