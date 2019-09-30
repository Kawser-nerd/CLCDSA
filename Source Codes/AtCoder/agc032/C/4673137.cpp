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

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

const int L=1e5+10;
vector<int> ps[L];
bool done[L];
void dfs(int p)
{
	done[p]=true;
	for(int i:ps[p])
	{
		if(!done[i])
		{
			dfs(i);
		}
	}
}
int main() {
	int N,M;
	cin >> N >> M;
	for(int i=0;i<M;i++)
	{
		int a,b;
		cin >> a >> b;
		ps[a].push_back(b);
		ps[b].push_back(a);
	}
	int cnt4=0;
	int cnt6=0;
	vector<int> v4;
	for(int i=1;i<=N;i++)
	{
		if(ps[i].size()%2)
		{
			cout << "No" << endl;
			return 0;
		}
		if(ps[i].size()==4)
		{
			cnt4++;
			v4.push_back(i);
		}
		else if(ps[i].size()>4)
		{
			cnt6++;
		}
	}
	if(cnt4==2&&cnt6==0)
	{
		done[v4[1]]=true;
		dfs(v4[0]);
		for(int i=1;i<=N;i++)
		{
			if(!done[i])
			{
				cout << "Yes" << endl;
				return 0;
			}
		}
		cout << "No" << endl;
		return 0;
	}

	if(cnt6>0||cnt4>1)
	{
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}

	return 0;
}