#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int t;
int n, a[105][55];
int cnt[2505];

int main(){
	cin >> t;
	for(int i=1; i<=t; i++){
		printf("Case #%d: ", i);
		memset(cnt, 0, sizeof(cnt));
		cin >> n;
		for(int i=0; i<2*n-1; i++){
			for(int j=0; j<n; j++){
				cin >> a[i][j];
				cnt[a[i][j]]++;
			}
		}
		for(int i=0; i<=2500; i++){
			if(cnt[i] & 1) printf("%d ",i);
		}
		puts("");
	}
}