/* 
 * in the name of god 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */ 

#include <iostream> 
#include <fstream> 
#include <sstream> 
#include <cstdio> 
#include <cstring> 
#include <cstdlib> 
#include <cmath> 
#include <ctime> 
#include <algorithm> 
#include <vector> 
#include <queue> 
#include <deque> 
#include <stack> 
#include <set> 
#include <map> 
#include <complex> 
#include <bitset> 
#include <iomanip> 
#include <utility> 

using namespace std; 

typedef long long LL; 
typedef pair<int,int> pii; 
typedef complex<double> point; 

int poi[1000];
string s[1000],t[1000];

inline void main2(){
	int n; cin >> n;
	for (int i=0; i<n; i++){
		cin >> s[i];
		t[i] = s[i][0];
		for (int j=1; j<(int)s[i].size(); j++) if (s[i][j] != s[i][j-1])
			t[i]+= s[i][j];
	}
	for (int i=0; i<n; i++)
		for (int j=i+1; j<n; j++) 
			if (t[i] != t[j]){
				cout << "Fegla Won" << endl;
				return;
			}
	for (int i=0; i<n; i++)
		poi[i] = 0;
	int ret = 0;
	for (int i=0; i<(int)t[0].size(); i++){
		vector <int> Q;
		for (int j=0; j<n; j++){
			int c = 0;
			while (poi[j]<(int)s[j].size() && s[j][poi[j]] == t[0][i])
				poi[j]++, c++;
			Q.push_back(c);
		}
		sort(Q.begin(), Q.end());
		for (int j=0; j<(int)Q.size(); j++)
			ret+= abs(Q[(int)Q.size()/2] - Q[j]);
	}
	cout << ret << endl;
}

int main(){
	int tt; cin >> tt;	
	for (int o=1; o<=tt; o++){
		cout << "Case #" << o << ": ";
		main2();
	}
	return 0;
}
