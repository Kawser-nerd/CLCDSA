#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
class Card{
	public:
		int c, s, t;
		bool operator<(const Card &c) const{
			return s < c.s;
		}
};

int getRemain(int t, priority_queue<Card> Q, priority_queue<Card> Q1) {
	int ret=0;

	while (t>0 && (Q.size()>0 || Q1.size()>0)) {
		if(Q.size()==0 || Q1.size()>0 && Q1.top().s > Q.top().s) {
			ret += Q1.top().s;
			Q1.pop();
			--t;
		} else if (Q1.size()==0 || Q.size()>0 && Q1.top().s <= Q.top().s) {
			ret += Q.top().s;
			Q.pop();
			--t;
		}
	}
	return ret;
}
int main(void) {
	int T, cs;
	int n, m, i;
	scanf("%d", &T);
	for(cs=1;cs<=T;cs++){
		scanf("%d", &n);
		Card c;
		priority_queue<Card> Q[3];
		queue<Card> QQ;
		int ac = 0, as = 0, at = 1;
		for(i=0;i<n;i++) {
			scanf("%d%d%d", &c.c, &c.s, &c.t);
			if(c.t>0) {
				ac += c.c;
				as += c.s;
				at += c.t - 1;
			}
			else {
				Q[c.c].push(c);
			}
		}
		scanf("%d", &m);
		for(i=0;i<m;i++){
			scanf("%d%d%d", &c.c, &c.s, &c.t);
			if (ac > 0) {
				--ac;
				if(c.t>0) {
					ac += c.c;
					as += c.s;
					at += c.t - 1;
				} else {
					Q[c.c].push(c);
				}
			} else {
				QQ.push(c);
			}
		}
		int ans = as + getRemain(at, Q[0], Q[1]);
		while (at > 0 && Q[1].size() > 0 && QQ.size() > 0) {
			Card tmp = Q[1].top();
			Q[1].pop();
			++ac;
			as += tmp.s;
			--at;
			if(at==0) {
				if (as > ans) ans = as;
				break;
			}
			do {
				Card f = QQ.front();
				QQ.pop();
				--ac;
				if (f.t > 0) {
					ac += f.c;
					as += f.s;
					at += f.t-1;
				} else {
					Q[f.c].push(f);
				}
			} while(ac > 0 && QQ.size()>0);
			int v = as + getRemain(at, Q[0], Q[1]);
			if (v > ans) ans = v;
		}
		printf("Case #%d: %d\n", cs, ans);
		fprintf(stderr, "Case #%d: %d\n", cs, ans);
	}
	return 0;
}
