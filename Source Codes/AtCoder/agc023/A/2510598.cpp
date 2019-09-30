#include<iostream>
#include<string>
#include<climits>
#include<vector>
#include <sstream>
#include<algorithm>
#include<array>
#include<map>

using namespace std;

int main(void) {

	int n;
	string in;

	cin >> n;

	vector<long long> sum(n+1);
	long long buf=0;

	for (int i = 1; i <= n;++i) {
		cin >> in;
		buf += stoll(in);
		sum[i] = buf;
	}

	sort(sum.begin(),sum.end());

	long long score=0,now,combo=0;
	now = sum[0];
	for (int i = 1;i <= n;++i) {
		if(now==sum[i]){
			combo++;
			score += combo;
		}
		else {
			now = sum[i];
			combo = 0;
		}
	}

	cout << score;
	return 0;

}