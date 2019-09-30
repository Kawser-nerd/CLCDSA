#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
	int A, B, Q;
	cin >> A >> B >> Q;

	vector<long long> j(A+2);
	vector<long long> t(B+2);

	j[0] = LLONG_MIN / 4;
	t[0] = LLONG_MIN / 4;
	j[j.size() - 1] = LLONG_MAX / 4;
	t[t.size() - 1] = LLONG_MAX / 4;

	for(int i = 1; i < j.size() - 1; i++) cin >> j[i];
	for(int i = 1; i < t.size() - 1; i++) cin >> t[i];

	for(int i = 0; i < Q; i++) {
		long long p;
		cin >> p;
		auto j_it = lower_bound(j.begin(), j.end(), p);
		auto t_it = lower_bound(t.begin(), t.end(), p);

		long long j_l, j_r, t_l, t_r;
		j_l = *(j_it - 1);
		j_r = *j_it;
		t_l = *(t_it - 1);
		t_r = *t_it;

		long long c = LLONG_MAX;

		// s l
		c = min(c, p - min(j_l, t_l));
		// s r
		c = min(c, max(j_r, t_r) - p);
		// l 2 r
		// tera first
		c = min(c, p - t_l + (j_r - t_l));
		// jinja first
		c = min(c, p - j_l + (t_r - j_l));
		// r 2 l
		//tera first
		c = min(c, t_r - p + (t_r - j_l));
		//jinja first
		c = min(c, j_r - p + (j_r - t_l));

		cout << c << endl;
	}

}