#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

const int inf = (int)1E+9;

typedef long long int64;
typedef pair<int,int> pii;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define all(a) a.begin(), a.end()
#define last(a) (int)a.size() - 1
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define norm(a) sort(all(a)); a.erase(unique(all(a)), a.end());
#define num(a, v) (int)(lower_bound(all(a), v) - a.begin())

int main(){
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);

	int tst;
	cin >> tst;
	forn(qwe,tst){
		string s;
		cin >> s;
		vector<int> q;
		forn(i,s.size())
			q.pb(s[i] - '0');

		bool done = 0;

		
		ford(i,q.size()){
			int now = -1;
			for (int j = i + 1; j < q.size(); j++)
				if (q[j] > q[i] && (now == -1 || q[j] < q[now])) now = j;
			if (now != -1){
					cerr << now << " " << i << endl;
					swap(q[now],q[i]);
					sort(q.begin() + i+1, q.end());
					done = 1;
					break;
				}
		}
		forn(i,q.size())
			cerr << q[i];
		cerr << endl;
		cerr << done << endl;
		if (done == 0){
			q.pb(0);
			sort(all(q));
			forn(i,q.size())
				if (q[i] != 0){
					swap(q[i],q[0]);
					break;
				}
		}	
		
		printf("Case #%d: ", qwe+1);
		forn(i,q.size())
			cout << q[i];
		cout << endl;
		//%I64d\n",qwe+1, res);
	}
			

}
