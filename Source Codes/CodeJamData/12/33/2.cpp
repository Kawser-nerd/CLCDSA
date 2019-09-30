#include <iostream>
#include <vector>
#include <tuple>
#include <map>
using namespace std;
typedef unsigned long long ull;

struct Items {
	int type;
	ull count;
};

struct State {
	int boxBatchCount, toyBatchCount;
	ull boxCount, toyCount;

	bool operator<(const State &s) const {
		return make_tuple(boxBatchCount, toyBatchCount, boxCount, toyCount) <
			make_tuple(s.boxBatchCount, s.toyBatchCount, s.boxCount, s.toyCount);
	}
};

std::map<State, ull> m;
std::vector<Items> boxes;
std::vector<Items> toys;

ull compute(const State &state_) {
	auto it = m.find(state_);
	if (it!=m.end())
		return it->second;
	ull res;
	if ((state_.boxBatchCount==0 && state_.boxCount==0) ||
		(state_.toyBatchCount==0 && state_.toyCount==0))
	{
		res = 0;
	} else {
		State state = state_;
		if (state.toyCount==0)
			state.toyCount = toys[--state.toyBatchCount].count;
		if (state.boxCount==0)
			state.boxCount = boxes[--state.boxBatchCount].count;
		if (toys[state.toyBatchCount].type==boxes[state.boxBatchCount].type) {
			res = min(state.toyCount, state.boxCount);
			state.toyCount -= res;
			state.boxCount -= res;
			res += compute(state);
		} else {
			State s1 = state;
			s1.toyCount = 0;
			ull res1 = compute(s1);
			State s2 = state;
			s2.boxCount = 0;
			ull res2 = compute(s2);
			res = max(res1, res2);
		}
	}
	m.insert(make_pair(state_, res));
	return res;
}

int main() {
	int T;
	cin >> T;
	for (int t=1; t<=T; t++) {
		m.clear();
		int n, m;
		cin >> n >> m;
		boxes.resize(n);
		toys.resize(m);
		for (int i=0; i<n; i++)
			cin >> boxes[i].count >> boxes[i].type;
		for (int i=0; i<m; i++)
			cin >> toys[i].count >> toys[i].type;
		State s;
		s.boxBatchCount = (int)boxes.size();
		s.toyBatchCount = (int)toys.size();
		s.boxCount = 0;
		s.toyCount = 0;
		cout << "Case #" << t << ": " << compute(s) << endl;
	}
	return 0;
}
