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


int sum0[2002][2002];
int sum1[2002][2002];
int sum2[2002][2002];
int N,M,Q;
void f(int sum[2002][2002])
{
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			sum[i][j]+=sum[i][j-1];
		}
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			sum[i][j]+=sum[i-1][j];
		}
	}
}
int g(int sum[2002][2002],int x1,int y1,int x2,int y2)
{
	return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
}
int main() {
	cin >> N >> M >> Q;
	char in[2002];
	for(int i=1;i<=N;i++)
	{
		cin >> (in+1);
		for(int j=1;j<=M;j++){
			if(in[j]=='1')
			{
				sum0[i][j]=1;
				if(sum0[i-1][j]==1)
				{
					sum1[i-1][j]=1;
				}
				if(sum0[i][j-1]==1)
				{
					sum2[i][j-1]=1;
				}
			}
		}
	}
	f(sum0);
	f(sum1);
	f(sum2);
	//cerr << sum0[N][M] << endl;
	for(int i=0;i<Q;i++){
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int s=g(sum0,x1,y1,x2,y2)
			-g(sum1,x1,y1,x2-1,y2)
			-g(sum2,x1,y1,x2,y2-1);
		cout << s << endl;
	}

	return 0;
}