#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <cstdlib>
#include <stack>
#include <climits>
#include <ctime>
#include <iomanip>
 
using namespace std;
 
typedef long long LL;
typedef double db;
#define lowbit(x) (x)&(-x)
#define gcd(a,b) __gcd(a,b)
#define sqre(x) (x)*(x)
#define mem(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
const int MaxN = 2e4 + 5;
const int inf = 1e8;
const double PI = acos(-1.0);
const LL mod = 100000007;

const int w = 1e4;
const int k = 5e3;
const int p = 1e3;
struct node{
	int cnt;
	int w,k,p;
	int sum(){
		return w+k+p;
	}
};

int main()
{
	int n,m;
	cin >> n >> m;
	if(m < (n*p) || m > (n*w)){
		cout << "-1" << " -1" << " -1" << endl; 
	}
	else{
		bool flag = true;
		for(int i = n ; i >= 0 && flag; i--)
			for(int j = n - i ; j >= 0 && flag; j--){
				int z = n - i - j;
				if(z < 0)continue;
				if(i*w + j*k + z*p == m){
					cout << i << " " << j << " " << z << endl;
					flag = false;
				}
			}
		if(flag)cout << "-1 -1 -1"<<endl;
	}
	return 0;
}