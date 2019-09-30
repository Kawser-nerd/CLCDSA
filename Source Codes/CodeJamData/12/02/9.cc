#include <iostream>
#include <vector>

int main() {
    int num_cases;
    std::cin >> num_cases;

    for (int casenum = 1; casenum <= num_cases; ++casenum) {
	int n;
	std::cin >> n;
	int s;
	std::cin >> s;
	int p;
	std::cin >> p;
	std::vector<int> t;
	for (int i = 0; i < n; ++i) {
	    int t_i;
	    std::cin >> t_i;
	    t.push_back(t_i);
	}

	// 3p-2 - totals at least this get in by non-surprising.
	// 3p-4 - totals at least this get in by surprising.

	// except when constrained below!

	// p >= 2: normal rules apply.
	// p = 1: totals of 1 are good, totals of 0 are no good.
	// p = 0: everybody's good.

	int s_used = 0;

	int possible = 0;

	for (int i = 0; i < n; ++i) {
	    if (p >= 2) {
		if (t[i] >= 3*p - 2) {
		    possible += 1;
		} else if (t[i] >= 3*p - 4 && s_used < s) {
		    s_used += 1;
		    possible += 1;
		}
	    } else if (p == 1) {
		if (t[i] > 0) {
		    possible += 1;
		}
	    } else {
		possible += 1;
	    }
	}

	std::cout << "Case #" << casenum << ": " << possible << "\n";
    }
}
