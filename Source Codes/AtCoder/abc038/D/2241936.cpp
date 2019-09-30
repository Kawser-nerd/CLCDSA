#include <iostream>
#include <fstream>
#include <string> 
#include <cmath>  
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <functional>
#include <cctype>

#define BIT(a) (1 << (a))

using namespace std;

vector<pair<int, int> >v;
int a[100005];
int lis[100005];

bool my_cmp(pair<int, int> a, pair<int, int>b){
	if (a.first < b.first) return true;
	else if(a.first == b.first && a.second > b.second) return true;
	else return false;
}

int solve(int n){
	lis[0] = a[0];
	int len = 1;
	for (int i = 1; i < n; i++){
		if (lis[len-1] < a[i]){
			lis[len++] = a[i];
		}else{
			*lower_bound(lis, lis + len, a[i]) = a[i];
		}
	}
	return len;
}

int main(void){
	int N;
	cin >> N;
	for (int i = 0; i < N; i++){
		int W, H;
		cin >> W >> H;
		v.push_back({W, H});
	}
	sort(v.begin(), v.end(), my_cmp);
	for (int i = 0; i < N; i++){
		a[i] = v[i].second;
	}

	int ans = solve(N);
	cout << ans << endl;


	return 0;

}