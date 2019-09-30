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
template <typename T, class Operator>
struct SegTree
{
	vector<T> tree;
	Operator op;
	T def;
	int s;
	SegTree(int size, T val, Operator opr)
	{
		s=size;
		op=opr;
		tree.resize(4*size,val);
		def=val;
	}

	void add(int pos, T value)
	{
		add(pos,value,0,s,0);
	}

	// [low, hi) ??????
	void add(int pos, T value, int low, int hi, int i)
	{
		while(1)
		{
			tree[i]=op(tree[i],value);
			if(low+1<hi){
				int mid=(low+hi)/2;
				if(pos<mid){
					i=2*i+1;
					hi=mid;
				}
				else
				{
					i=2*i+2;
					low=mid;
				}
			}
			else
			{
				break;
			}
		}
	}

	// [a,b) ???
	T get(int a, int b)
	{
		return get(a,b,0,s,0);
	}

	T get(int a, int b, int low, int hi, int i)
	{
		if(hi<=a||b<=low||hi<=low){
			return def;
		}
		if(a<=low&&hi<=b){
			return tree[i];
		}
		int mid=(low+hi)/2;
		return op(get(a,b,low,mid,2*i+1),get(a,b,mid,hi,2*i+2));
	}
};
template<typename T>
struct Min
{
	T operator()(T a, T b){
		return min(a,b);
	}
};

const int L=200*1000+10;
LL x[L];
LL sum[L];
const LL inf=1LL<<60;
int main() {
	int N,Q,A,B;
	cin >> N >> Q >> A >> B;
	for(int i=0;i<Q;i++){
		cin >> x[i];
	}
	for(int i=Q-2;i>=0;i--)
	{
		sum[i]=sum[i+1]+abs(x[i]-x[i+1]);
	}
	SegTree<LL,Min<LL> > ltree(N+2,inf,Min<LL>()),rtree(N+2,inf,Min<LL>());
	LL ret=min(abs(B-x[0]),abs(A-x[0]))+sum[0];
	ltree.add(A,abs(B-x[0])+sum[0]-A);
	ltree.add(B,abs(A-x[0])+sum[0]-B);
	rtree.add(A,abs(B-x[0])+sum[0]+A);
	rtree.add(B,abs(A-x[0])+sum[0]+B);
	for(int i=1;i<Q;i++)
	{
		LL v=ltree.get(0,x[i])-sum[i-1]+x[i]+sum[i];
		LL w=rtree.get(x[i],N+1)-sum[i-1]-x[i]+sum[i];
		v=min(v,w);
		ret=min(ret,v);
		ltree.add(x[i-1],v-x[i-1]);
		rtree.add(x[i-1],v+x[i-1]);
	}
	cout << ret << endl;


	return 0;
}