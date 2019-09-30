#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <thread>
#include <mutex>
#include <iomanip>

using namespace std;
#define MOD @
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int n_testcases;
i64 A, B;
string R;

vector<pair<int, int> > nfa[100];
bool eps[100][100]; i64 etarget[100];
int idx;

int pos;

typedef pair<int, int> stat;

stat singleton(int i)
{
	int p = idx++;
	int q = idx++;
	nfa[p].push_back({q, i});
	return {p, q};
}
stat join(stat a, stat b)
{
	nfa[a.second].push_back({b.first, -1}); // epsilon
	return {a.first, b.second};
}
stat cases(vector<stat> &s)
{
	int p = idx++;
	int q = idx++;
	for (stat st : s) {
		nfa[p].push_back({st.first, -1});
		nfa[st.second].push_back({q, -1});
	}
	return {p, q};
}
stat loop(stat a)
{
	int p = idx++;
	nfa[p].push_back({a.first, -1});
	nfa[a.second].push_back({p, -1});
	return {p, p};
}

i64 epsilon(i64 v)
{
	i64 ans = 0;
	for (int i = 0; i < idx; ++i) if (v & (1LL << (i64)i)) {
		ans |= etarget[i];
	}
	return ans;
}
i64 trans(i64 v, int c)
{
	i64 ans = 0;
	for (int i = 0; i < idx; ++i) if (v & (1LL << (i64)i)) {
		for (auto a : nfa[i]) if (a.second == c) ans |= 1LL << (i64)a.first;
	}
	return epsilon(ans);
}
stat parse()
{
	stat ans{-1, -1};
	for (;;) {
		stat nxt;
		if (R[pos] == '(') {
//	fprintf(stderr, "%d, %d\n", ans.first, ans.second);
			++pos;
			vector<stat> subs;
			for (;;) {
				subs.push_back(parse());
				if (R[pos] == '|') ++pos;
				else if(R[pos] == ')') break;
			}
			++pos;
			
			if (R[pos] == '*') {
				++pos;
				nxt = loop(subs[0]);
			} else {
				nxt = cases(subs);
			}
		} else if (R[pos] >= '0' && R[pos] <= '9') {
//	fprintf(stderr, "%d, %d\n", ans.first, ans.second);
			nxt = singleton(R[pos] - '0');
			++pos;
		} else break;
		
		if (ans.first == -1) ans = nxt;
		else ans = join(ans, nxt);
	}
//	fprintf(stderr, "%d, %d\n", ans.first, ans.second);
	return ans;
}

int dfa[1 << 17][10];
int didx;
map<i64, int> dic;
i64 counts[1 << 17][20];

i64 visit(i64 s)
{
//	printf("%lld\n", s);
	if (dic.count(s)) return dic[s];
	int my = didx++;
	dic[s] = my;
	
	for (int i = 0; i < 10; ++i) {
		dfa[my][i] = visit(trans(s, i));
	}
	return my;
}

i64 solve(i64 mx)
{
	if (mx == 0) {
		return counts[dfa[0][0]][0];
	}
	
	ostringstream ss;
	ss << mx;
	string st = ss.str();
	
	i64 ret = 0;
	// zero?
	ret += counts[dfa[0][0]][0];

	//less digits
	for (int i = 1; i < 10; ++i) {
		for (int j = 0; j < st.size() - 1; ++j)
		ret += counts[dfa[0][i]][j];
	}
	int state = 0;
	for (int i = 0; i < st.size(); ++i) {
		for (int j = (i == 0 ? 1 : 0); j < (st[i] - '0'); ++j) {
			ret += counts[dfa[state][j]][st.size() - 1 - i];
		}
		state = dfa[state][st[i] - '0'];
	}
	ret += counts[state][0];
	return ret;
}

int main()
{
	scanf("%d", &n_testcases);
	
	for (int t = 0; t < n_testcases; ++t) {
		scanf("%lld%lld", &A, &B);
		char in[40];
		scanf("%s", in);
		R = in;
		
		idx = 0;
		for (int i = 0; i < 100; ++i) nfa[i].clear();
		pos = 0;
		stat s = parse();
	//	printf("%d, %d\n", s.first, s.second);
		
	//	for (int i = 0; i < idx; ++i) {
	//		for (auto a : nfa[i]) printf("%d -> (%d) %d\n", i, a.second, a.first);
	//	}
		for (int i = 0; i < idx; ++i) {
			for (int j = 0; j < idx; ++j) {
				eps[i][j] = (i == j);
			}
		}
		for (int i = 0; i < idx; ++i) {
			for (auto a : nfa[i]) {
				if (a.second == -1) eps[i][a.first] = true;
			}
		}
		for (int i = 0; i < idx; ++i) {
			for (int j = 0; j < idx; ++j) {
				for (int k = 0; k < idx; ++k) {
					eps[j][k] |= eps[j][i] && eps[i][k];
				}
			}
		}
		for (int i = 0; i < idx; ++i) {
			etarget[i] = 0;
			for (int j = 0; j < idx; ++j) if (eps[i][j]) etarget[i] |= (1LL << (i64)j);
		}
		
		didx = 0;
		dic.clear();
		i64 vis = visit(epsilon((1LL << (i64)s.first)));
	//	printf("%d\n", didx);
	//	for (int i = 0; i < didx; ++i) {
	//		for (int j = 0; j < 10; ++j) printf("%d ", dfa[i][j]);
	//		puts("");
	//	}
		for (int i = 0; i < didx; ++i) counts[i][0] = 0;
	//	counts[st][0] = 1;
		for (auto p : dic) if (p.first & (1LL << (i64)s.second)) counts[p.second][0] = 1;
		for (int i = 1; i < 20; ++i) {
			for (int j = 0; j < didx; ++j) {
				counts[j][i] = 0;
				for (int k = 0; k < 10; ++k) counts[j][i] += counts[dfa[j][k]][i - 1];
	//			printf("%d %d %lld\n", i - 1, j, counts[j][i - 1]);
			}
		}
	//	printf("%lld %lld\n", solve(B), solve(A - 1));
		printf("Case #%d: %lld\n", t + 1, solve(B) - solve(A - 1));
	}
	
	return 0;
}
