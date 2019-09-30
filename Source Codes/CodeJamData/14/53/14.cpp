#include <stdio.h>
#include <set>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int dat[20][2];
int dt[20][1<<16];

int main(){
	int T;
	scanf("%d",&T);
	for(int testcase = 1; testcase <= T; testcase++) {
		scanf("%d",&n);
		set<int> numbers;
		int mask = 0;
		for(int i = 0; i < n; i++) {
			char cmd[4];
			int num;
			scanf("%s%d",cmd,&num);
			dat[i][0] = (cmd[0] == 'L');
			dat[i][1] = num;
			if (num == 0) mask |= (1<<i);
			if (num > 0) numbers.insert(num);
		}
		map<int,int> state;
		int p = numbers.size();
		vector<int> numbersVector(numbers.begin(),numbers.end());

		//convert
		for(int i = 0; i < n; i++) {
			if (dat[i][1] > 0) {
				dat[i][1] = lower_bound(numbersVector.begin(),numbersVector.end(), dat[i][1]) - numbersVector.begin() + 1;
			}
		}

		bool possible = false;
		int ans = n+1;
		for(int i = (((1<<n)-1)&mask); i >= 0; i = ((i-1)&mask)) {
			for(int j = 0; j < (1<<p); j++) {
				dt[0][j] = 1;
			}
			int matchingCnt = 0;
			for(int j = 0; j < n; j++) {
				memset(dt[j+1],0,sizeof(dt[j+1][0]) * (1<<p));
				if (i & (1<<j)) {
					if (dat[j][0] == 0) {
						matchingCnt++;
					} else {
						matchingCnt--;
						if (matchingCnt < 0) matchingCnt = 0;
					}
					memcpy(dt[j+1], dt[j], sizeof(dt[j+1][0]) * (1<<p));
				} else if (dat[j][1] == 0) {
					for(int k = 0; k < (1<<p); k++){
						if (dt[j][k]==0)continue;
						for(int l = 0; l < p; l++) {
							if ((k & (1<< l)) && dat[j][0]) {
								dt[j+1][k^(1<<l)] = 1;
							} else if (!(k & (1<< l)) && !dat[j][0]) {
								dt[j+1][k^(1<<l)] = 1;
							}
						}
					}
				} else {
					int curBit = (1<<(dat[j][1] - 1));
					for(int k = 0; k < (1<<p); k++){
						if (dt[j][k]==0)continue;
						if ((k & curBit) && dat[j][0]) {
							dt[j+1][k^curBit] = 1;
						} else if(!(k & curBit) && !dat[j][0]) {
							dt[j+1][k^curBit] = 1;
						}
					}
				}
			}
			int minCnt = 10000;
			for(int k = 0; k < (1<<p); k++) {
				if (dt[n][k]) {
					int cnt = 0;
					for(int l = 0; l < p; l++) {
						if (k & (1<<l)) cnt++;
					}
					minCnt = min(minCnt,cnt);
				}
			}

			if (minCnt != 10000) {
				possible = true;
				ans = min(ans, minCnt + matchingCnt);
			}

			if (i == 0) break;
		}

		if (!possible) {
			printf("Case #%d: CRIME TIME\n", testcase);
			continue;
		}
		printf("Case #%d: %d\n", testcase, ans);
	}
	return 0;
}
