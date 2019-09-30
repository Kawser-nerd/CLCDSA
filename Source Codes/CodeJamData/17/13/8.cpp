#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

const int inf = 1e9 + 5;

void test_case() {
	int my_hp, my_attack, his_hp, his_attack, buf, debuf;
	cin >> my_hp >> my_attack >> his_hp >> his_attack >> buf >> debuf;
	int init_hp = my_hp;
	int answer = inf;
	
	for(int times_debuf = 0; times_debuf <= 200; ++times_debuf)
		for(int times_buf = 0; times_buf <= 200; ++times_buf) {
			vector<int> memo{my_hp, my_attack, his_hp, his_attack};
			for(int turn = 1; turn <= 600; ++turn) {
				if(his_hp <= my_attack) {
					answer = min(answer, turn);
					break;
				}
				if(my_hp <= his_attack && !(turn <= times_debuf && my_hp > his_attack - debuf)) {
					my_hp = init_hp;
				}
				else if(turn <= times_debuf)
					his_attack -= debuf;
				else if(turn <= times_debuf + times_buf)
					my_attack += buf;
				else {
					his_hp -= my_attack;
					assert(his_hp > 0);
				}
				my_hp -= his_attack;
				if(my_hp <= 0) break;
			}
			my_hp = memo[0], my_attack = memo[1], his_hp = memo[2], his_attack = memo[3];
		}
	
	if(answer == inf) puts("IMPOSSIBLE");
	else printf("%d\n", answer);
}

int main() {
	int T;
	cin >> T;
	for(int nr = 1; nr <= T; ++nr) {
		printf("Case #%d: ", nr);
		test_case();
	}
}
