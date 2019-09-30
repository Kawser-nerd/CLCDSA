#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <iomanip>

#define ll long long int
#define pb push_back
#define mk make_pair
#define pq priority_queue

using namespace std;
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
const int inf = 1e9;
const ll linf = 1LL << 50;

int n, m;
set<int> st[9];

int main(int argc, char const* argv[])
{
	cin >> n >> m;
	vector<int> vec;
	for(int i = 0; i < n; i++)vec.pb(i);
	for(int i = 0; i < m; i++){
			int a, b;
			cin >> a >> b;
			a--; b--;
			st[a].insert(b);
			st[b].insert(a);
	}
	int res = 0;
	do{
			if(vec[0] != 0)continue;
			for(int i = 0; i < n - 1; i++){
					if(st[vec[i]].find(vec[i+1]) == st[vec[i]].end())break;
					if(i == n - 2)res++;
			}
	}while(next_permutation(vec.begin(), vec.end()));
	cout << res << endl;
	return 0;
}