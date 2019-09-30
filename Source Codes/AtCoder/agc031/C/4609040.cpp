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


vector<int> vs[18];
int bc(int a)
{
	int r=0;
	for(int i=0;i<18;i++)
	{
		if(a&(1<<i))
		{
			r++;
		}
	}
	return r;
}


int g(int v,int i,int N)
{
	int r=0;
	for(int j=0;j<i;j++)
	{
		r|=v&(1<<j);
	}
	for(int j=i;j+1<N;j++)
	{
		r|=(v&(1<<(j+1)))>>1;
	}
	return r;
}
int h(int v,int i,int N)
{
	int r=0;
	for(int j=0;j<i;j++)
	{
		r|=v&(1<<j);
	}
	for(int j=i+1;j<N;j++)
	{
		r|=(v&(1<<(j-1)))<<1;
	}
	return r;
}
vector<int> f(int N,int A,int B){
	if(N==1)
	{
		return {A,B};
	}
	for(int i=0;i<N;i++)
	{
		if((A&(1<<i))!=(B&(1<<i)))
		{
			int a=g(A,i,N);
			int b=g(B,i,N);
			vector<int> ret;
			for(auto v:f(N-1,a,a^1))
			{
				ret.push_back(h(v,i,N)|(A&(1<<i)));
			}
			for(auto v:f(N-1,a^1,b))
			{
				ret.push_back(h(v,i,N)|(B&(1<<i)));
			}
			return ret;
		}
	}
	return {};
}

int main()
{
	int N,A,B;
#if 1
	cin >> N>>A >> B;
	if(bc(A)%2==bc(B)%2)
	{
		cout << "NO" << endl;
		return 0;
	}
	auto v=f(N,A,B);
	cout << "YES" << endl;
	auto sp="";
	for(auto v:f(N,A,B))
	{
		cout << sp << v;
		sp=" ";
	}
	cout << endl;
#else
  std::mt19937 rand_src(12345);
	for(int i=0;i<20;i++)
	{
  std::uniform_int_distribution<int> rand_dist(1, 5);
  N=rand_dist(rand_src);
  uniform_int_distribution<int> rd2(0,(1<<N)-1);
  A=rd2(rand_src);
  B=rd2(rand_src);
  cerr << N << ", " << A << ", " << B << endl;
  f(N,A,B);
	}
#endif
}