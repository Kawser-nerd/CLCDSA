#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){
	int T; cin >> T;
	long long A; int N;
	for(int test=1;test<=T;test++){
		cin >> A >> N;
		vector<int> v;
		for(int i=0;i<N;i++){
			int t; cin >> t;
			v.push_back(t);
		}
		sort(v.begin(), v.end());
		int res = N;
		int cnt = 0;
		if(A > 1){
			for(int i=0;i<N;i++){
				res = min(res, cnt+N-i);
				while(v[i] >= A){
					A += A-1;
					cnt++;
				}
				A += v[i];
			}
			res = min(res, cnt);
		}
		printf("Case #%d: %d\n", test, res);
	}
}
