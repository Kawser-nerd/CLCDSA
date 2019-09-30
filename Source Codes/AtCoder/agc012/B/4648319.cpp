#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <array>
#include <bitset> 
#include <unordered_map>
#include <random>

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

const int L=1e5+10;
vector<int> ps[L];
int ds[L];
int v[L];
int d[L];
int c[L];
int r[L];
int main() {
	int N,M,Q;
	cin >> N >> M;
	memset(ds,-1,sizeof(ds));
	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		ps[a].push_back(b);
		ps[b].push_back(a);
	}
	cin >> Q;
	//cerr << "aaa " << Q << endl;
	for(int i=0;i<Q;i++){
		cin >> v[i] >> d[i] >> c[i];
	}
	//cerr << "bbb" << endl;
	for(int i=Q-1;i>=0;i--)
	{
		if(ds[v[i]]>=d[i])
		{
			continue;
		}
		ds[v[i]]=d[i];
		vector<int> cur,nex;
		if(r[v[i]]==0)
		{
			r[v[i]]=c[i];
		}
		cur.push_back(v[i]);
		for(int j=d[i]-1;j>=0;j--)
		{
			//cerr << i << ", " << j << endl;
			nex.clear();
			for(auto w:cur){
				for(auto k:ps[w])
				{
					if(ds[k]<j)
					{
						ds[k]=j;
						if(r[k]==0){
							r[k]=c[i];
						}
						nex.push_back(k);
					}
				}
			}
			nex.swap(cur);
		}
	}
	for(int i=1;i<=N;i++)
	{
		cout << r[i] << endl;
	}


	return 0;
}