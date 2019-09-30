#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <functional>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

bool is_valid(vector<bool>&a) {
	if (a.size() == 1)return true;
	for (auto itr = a.begin(); itr != a.end() - 1; ++itr) {
		if (*itr == true && *(itr + 1) == true) {
			return false;
		}
	}
	return true;
}
long long int searchroute(vector<int>& Wexists, vector<int>& Wnexists, int H,int W,int K,int pos) {
	long long int num = 0;
	static vector<pair<vector<int>,long long int> >memo;

	if (H == 0&&K==pos)return 1;
	if (abs(K - pos) > H)return 0;
	for (auto a : memo) {
		if (a.first[0] == H&&a.first[1] == W&&a.first[2] == K&&a.first[3] == pos) {
			return a.second;
		}
	}
	num+=Wnexists[pos-1]*searchroute(Wexists,Wnexists, H - 1, W, K, pos)%1000000007;
	if (pos != 1)num +=Wexists[pos-2]*searchroute(Wexists, Wnexists, H - 1, W, K, pos - 1) % 1000000007;
	if (pos != W)num +=Wexists[pos-1]*searchroute(Wexists, Wnexists, H - 1, W, K, pos + 1) % 1000000007;
	num %= 1000000007;
	pair<vector<int>, long long int> aa({ H,W,K,pos},num) ;
	memo.push_back(aa);
	return num;
}
int main() {
	int H, W, K;
	cin >> H >> W >> K;
	//i??i+1??????i???0->W-2
	if (W == 1) {
		cout << 1<<endl;
		return 0;
		//???????1
	}
	vector<bool> valid(W - 1, false);
	vector<vector<bool> > valids;
	vector<int> Wexsists(W-1,0);//????????
	vector<int> Wnexsists(W,0);//?i-1?????????
	bool flag = true;
	while(flag){
		if (is_valid(valid)) {
			//std::vector<bool> tmp;
			valids.push_back(valid);
			//copy(valid.begin(), valid.end(), back_inserter(valids));
		}
		for (auto itr = valid.begin(); itr != valid.end(); ++itr) {
			if (*itr == false) {
				*itr = true;
				break;
			}else {
				if (itr == valid.end() - 1) {
					flag = false;
				}
				else {
					*itr = false;
				}
			}
		}
		//if (!flag)break;
	}
	for (auto a : valids) {
		//for (auto b : a) { cout << b; }
		//cout << endl;
		for (int i = 0; i < W - 1;++i) {
			if (a[i] == true) {
				Wexsists[i] += 1;
			}
			if (i != W - 2) {
				if (a[i] == false && a[i+1] == false) {
					Wnexsists[i + 1] += 1;
				}
			}
		}
		if (a[0] == false)Wnexsists[0] += 1;
		if (a[W - 2] == false)Wnexsists[W - 1] += 1;
		//cout << endl;
	}
	/*for (auto a : Wnexsists) {
		cout << a;
	}cout << endl;*/
	cout << searchroute(Wexsists, Wnexsists, H, W, K, 1);
	return 0;
}