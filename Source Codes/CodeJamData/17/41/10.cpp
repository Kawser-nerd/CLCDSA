#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstdlib>
#include <ctime>
#include <deque>
using namespace std;

map <vector<int>, int> Map;

int calc(vector <int> s) {
	if (Map.count(s))
		return Map[s];
	int ans = 0;
	int sum = 0;
	for (int i = 0; i < (int) s.size(); i++)
		sum += i * s[i];
	for (int i = 0; i < (int) s.size(); i++)
		if (s[i] > 0) {
			vector <int> s1;
			for (int j = 0; j < (int) s.size(); j++)
				s1.push_back(s[j]);
			s1[i] -= 1;
			ans = max(ans, calc(s1) + ((sum - i) % s.size() == 0));
		}
	return Map[s] = ans;
}

void doit() {
	int n, p;
	scanf("%d%d", &n, &p);
	vector <int> s;
	for (int i = 0; i < p; i++)
		s.push_back(0);
	while (n--) {
		int x;
		scanf("%d", &x);
		s[x % p] += 1;
	}
	printf("%d\n", calc(s));
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        printf("Case #%d: ", i);
        doit();
    }
}