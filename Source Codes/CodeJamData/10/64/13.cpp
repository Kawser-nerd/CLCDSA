#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<long long> xs;
vector<long long> dist;
long long f;

void fill(int begin, int end, int beginCount, int endCount, vector<long long> &res) {
	if (abs(endCount-beginCount)>2*(end-begin))
		return;
	if (begin==end) {
		if (beginCount==endCount)
			res.push_back(0);
		return;
	}
	for (int prevCount=endCount-2; prevCount<=endCount+2; prevCount+=2) {
		if (prevCount<1)
			continue;
		unsigned int lastSize = res.size();
		fill(begin, end-1, beginCount, prevCount, res);
		for (unsigned int i=lastSize; i<res.size(); i++)
			if (res[i]!=-1) {
				long long myDist = dist[end-1]*prevCount;
				if (myDist>f) res[i] = -1;
				else {
					res[i] += myDist;
					if (res[i]>f) res[i] = -1;
				}
			}
	}
}

long long runTest() {
	vector<long long> d1, d2;
	int mid = dist.size()/2;
	long long best = -1;
	for (int count=2; ; count+=2) {
		d1.clear();
		d2.clear();
		fill(0, mid, 2, count, d1);
		fill(mid, dist.size(), count, 0, d2);
		sort(d1.rbegin(), d1.rend());
		sort(d2.rbegin(), d2.rend());
		while (!d1.empty() && d1.back()==-1) d1.pop_back();
		while (!d2.empty() && d2.back()==-1) d2.pop_back();
		if (d1.empty() || d2.empty())
			break;
		int i = 0;
		int j = d2.size()-1;
		for (;;) {
			if (d1[i]+d2[j]>f) {
				i++;
				if (i>=(int)d1.size())
					break;
				else
					continue;
			}
			if (d1[i]+d2[j]>best)
				best = d1[i]+d2[j];
			j--;
			if (j<0)
				break;
		}
	}
	return best;
}

int main() {
	int T;
	cin >> T;
	for (int t=1; t<=T; t++) {
		int n;
		cin >> n;
		xs.resize(n);
		for (int j=0; j<n; j++)
			cin >> xs[j];
		cin >> f;
		sort(xs.begin(), xs.end());
		dist.resize(n-1);
		for (int j=1; j<n; j++)
			dist[j-1] = xs[j]-xs[j-1];
		long long ans = runTest();
		if (ans>=0)
			cout << "Case #" << t << ": " << ans << endl;
		else
			cout << "Case #" << t << ": " << "NO SOLUTION" << endl;
		cerr << t << "/" << T << endl;
	}
	return 0;
}
