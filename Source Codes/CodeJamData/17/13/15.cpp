#include <bits/stdc++.h>
using namespace std;

int TC, Hd, Ad, Hk, Ak, B, D;

bool attempt(int x) {
	int myhealth = Hd;
}

int main() {
	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; tc++) {
		scanf("%d%d%d%d%d%d", &Hd, &Ad, &Hk, &Ak, &B, &D);
		
		int ans = 1000000000;
		for (int debuffs = 0; debuffs <= 100; debuffs++) {
			for (int buffs = 0; buffs <= 100; buffs++) {
				int myhealth = Hd, oppHealth = Hk, myAttack = Ad, oppAttack = Ak, turns = 0;
				bool fail = 0;
				for (int i = 0; i < debuffs; i++) {
					int futAttack = max(0, oppAttack - D);
					if (myhealth <= futAttack) {
						turns++;
						if (turns > 1000) {
							fail = 1;
							break;
						}
						myhealth = Hd;
						myhealth -= oppAttack;
						i--;
						continue;
					} else {
						oppAttack = futAttack;
						myhealth -= oppAttack;
						turns++;
					}
				}
				if (fail) continue;
				for (int i = 0; i < buffs; i++) {
					if (myhealth <= oppAttack) {
						turns++;
						if (turns > 1000) {
							fail = 1;
							break;
						}
						myhealth = Hd;
						myhealth -= oppAttack;
						i--;
						continue;
					} else {
						myAttack += B;
						myhealth -= oppAttack;
						turns++;
					}
				}
				if (fail) continue;
				while (1) {
					if (myhealth <= oppAttack && oppHealth > myAttack) {
						turns++;
						if (turns > 1000) {
							fail = 1;
							break;
						}
						myhealth = Hd;
						myhealth -= oppAttack;
						continue;
					} else {
						turns++;
						oppHealth -= myAttack;
						if (oppHealth <= 0) break;
						myhealth -= oppAttack;
					}
				}
				if (fail) continue;
				ans = min(ans, turns);
			}
		}
		if (ans == 1000000000) printf("Case #%d: IMPOSSIBLE\n", tc);
		else printf("Case #%d: %d\n", tc, ans);
		
		/*int bot = 0, top = 1000000005, mid;
		while (bot + 1 < top) {
			mid = (bot + top) / 2;
			if (attempt(mid)) top = mid;
			else bot = mid;
		}
		if (bot + 1 > 1000000000) printf("Case #%d: IMPOSSIBLE\n", tc);
		else printf("Case #%d: %d\n", tc, bot + 1);*/
	}
}
