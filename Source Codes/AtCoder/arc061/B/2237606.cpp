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

set<pair<long long, long long> > black;
set<pair<long long, long long> > rac;

long long ans[10];

int main(void){
	long long h, w, n;
	cin >> h >> w >> n;
	for (int i = 0; i < n; i++){
		long long x, y;
		cin >> x >> y;
		black.insert(make_pair(x, y));
		for (int j = 0; j < 3; j++){
			for (int k = 0; k < 3; k++){
				rac.insert(make_pair((x-j), (y-k)));
			}
		}
	}

	ans[0] = (h-2)*(w-2);

	for (auto itr = rac.begin(); itr != rac.end(); ++itr){
		long long x, y;
		x = itr->first;
		y = itr->second;

		if (x <= 0 || x + 2 > h || y <= 0 || y + 2 > w) continue;

		int cnt = 0;

		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				cnt += black.count(make_pair((x+i), (y+j)));
			}
		}

		ans[cnt]++;
		ans[0]--;
	}

	for(int i = 0; i < 10; i++){
		cout << ans[i] << endl;
	}
	
	return 0;

}