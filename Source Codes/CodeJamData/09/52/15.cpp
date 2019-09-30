#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
using namespace std;

struct Word {
	int count[26];
	void set(const string &w);
};

void Word::set(const string &w) {
	fill(count, count+26, 0);
	for (unsigned int i=0; i<w.size(); i++)
		count[(int)w[i]-'a']++;
}

const int M = 10009;

vector<Word> words;

string poly;
int k;

map<pair<int, string>, int> cache;

static int simplePoly(const string &p, int len, int k) {
	map<pair<int, string>, int>::const_iterator it = cache.find(make_pair(k, p));
	if (it!=cache.end())
		return it->second;
	if (k==1) {
		int res = 0;
		for (unsigned int word=0; word<words.size(); word++) {
			int value = 1;
			for (int i=0; i<len; i++)
				value = (value * words[word].count[p[i]-'a']) % M;
			res += value;
		}
		res = res % M;
		cache[make_pair(k, p)] = res;
		return res;
	}

	int res = 0;
	string subp;
	for (unsigned int lastWord = 0; lastWord<words.size(); lastWord++) {
		for (int mask=0; mask<(1<<len); mask++) {
			subp = "";
			int factor = 1;
			for (int i=0; i<len; i++)
				if ((mask>>i)&1)
					subp += p[i];
				else
					factor = (factor * words[lastWord].count[p[i]-'a']) % M;
			res = (res + factor*simplePoly(subp, (int)subp.size(), k-1)) % M;
		}
	}
	cache[make_pair(k, p)] = res;
	return res;
}

static void runTest(vector<int> &sums) {
	sums.resize(k);
	fill(sums.begin(), sums.end(), 0);
	const char *p = poly.c_str();
	string sp;
	while (*p) {
		int len;
		for (len=0; p[len]!='+' && p[len]!=0; len++);
		sp.resize(len);
		for (int i=0; i<len; i++)
			sp[i] = p[i];
		for (int i=0; i<k; i++)
			sums[i] += simplePoly(sp, len, i+1);
		p += len;
		if (*p=='+')
			p++;
	}
	for (int i=0; i<k; i++)
		sums[i] = sums[i] % M;
}

int main() {
	int t;
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	cin >> t;
	string word;
	for (int ii=1; ii<=t; ii++) {
		cache.clear();
		cin >> poly >> k;
		int n;
		cin >> n;
		words.resize(n);
		for (int i=0; i<n; i++) {
			cin >> word;
			words[i].set(word);
		}
		vector<int> sums(k);
		runTest(sums);
		cout << "Case #" << ii << ": ";
		for (int i=0; i<k; i++)
			cout << ' ' << sums[i];
		cout << endl;
	}
	return 0;
}
