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
typedef LL T;
typedef pair<T,T> P;

// difference
P operator-(const P& lhs, const P& rhs)
{
	return P(lhs.first-rhs.first,lhs.second-rhs.second);
}

P operator+(const P& lhs, const P& rhs)
{
	return P(lhs.first+rhs.first, lhs.second+rhs.second);
}

// scalar product
P operator*(T t, P p){
	return P(t*p.first,t*p.second);
}

P operator/(P p, T t){
	return P(p.first/t,p.second/t);
}

P rot(P p){
	return P(-p.second,p.first);
}

// cross product
T Cross(const P& lhs, const P& rhs)
{
	return lhs.first*rhs.second-lhs.second*rhs.first;
}

P p[100];
int main() {
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		int x,y;
		cin >> x >> y;
		p[i]=P(x,y);
	}
	int ret=0;
	for(int i=0;i<N;i++)
		for(int j=i+1;j<N;j++)
			for(int k=j+1;k<N;k++){
				auto u=p[j]-p[i];
				auto v=p[k]-p[i];
				LL a=Cross(u,v);
				if(a!=0&&a%2==0){
					ret++;
				}
			}

	cout << ret << endl;


	return 0;
}