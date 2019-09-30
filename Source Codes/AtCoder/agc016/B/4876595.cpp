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

const int L=1e5;
int a[L];
int N;
bool f()
{
	if(abs(a[0]-a[N-1])>1){
		return false;
	}

	if(a[0]==1)
	{
		if (a[N-1]==1){
			return true;
		}
		return a[1]==2;
	}

	if(a[0]==a[N-1] && a[0]==N-1){
		return true;
	}


	int c=lower_bound(a,a+N,a[N-1])-a;
	return c+(N-c)/2>=a[N-1] && a[N-1]>=c+1;
}
int main() {
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> a[i];
	}
	sort(a,a+N);
	if(f())
	{
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}
	

	return 0;
}