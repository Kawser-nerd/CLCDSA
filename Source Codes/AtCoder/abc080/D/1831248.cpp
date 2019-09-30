#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct record {
	int s, t, c;
	bool operator<(const record& right)const {
		if (s != right.s) {
			return s < right.s;
		}
		else {
			return t < right.t;
		}
	}
};

int n, C, info[30][2];
vector<record> r;

int main() {
	cin >> n >> C;
	for (int i = 0; i < n; i++) {
		int s, t, c;
		cin >> s >> t >> c;
		r.push_back(record{ s, t, c });
	}

	sort(r.begin(), r.end());

	bool flag = true;
	int i;
	for (i = 0; i < C; i++) {
		//cout << (i+1) << "?????????" << endl;
		for (int j = 0; j < n; j++) {
			//cout << " j:" << j << endl;
			for (int k = 0; k <= i; k++) {//k???????
				//cout << "  k:" << k << endl;
				record re = r.at(j);
				if (info[k][0] <= re.s - 0.5 || (info[k][0] <= re.s && (info[k][1] == 0 || info[k][1] == re.c))) {
					//cout << "  " << j << "??????" << endl;
					info[k][0] = re.t;
					info[k][1] = re.c;
					break;
				}
				if (k == i)flag = false;
			}
		}
		if (flag)break;
		for (int j = 0; j <= i; j++) {
			for (int k = 0; k < 2; k++)info[j][k] = 0;
		}
		flag = true;
	}

	cout << (i + 1) << endl;
}