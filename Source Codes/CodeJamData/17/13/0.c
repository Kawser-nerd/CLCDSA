#include <stdio.h>
#include <string.h>
#include <string.h>
#include <inttypes.h>

#define IMPOSSIBLE 20000000000000

void aux(char *s, int i, int incr) {
	int prev = '?';
	while (s[i]) {
		if (s[i] == '?')
			s[i] = prev;
		prev = s[i];
		i += incr;
	}
}

int64_t combat_duration(
		int hd, int ad,
		int hk, int ak,
		int b, int d,
		int n_debuffs,
		int n_buffs
) {
	int dragon_hp = hd;
	int knight_hp = hk;
	int healed_last_turn = 0;
	int64_t n = 0;
	while (1) {
		if (knight_hp <= ad) {
			knight_hp -= ad;
			healed_last_turn = 0;
		} else if ((n_debuffs > 0) && (dragon_hp > (ak - d))) {
			ak -= d;
			if (ak < 0) ak = 0;
			n_debuffs--;
			healed_last_turn = 0;
		} else if (dragon_hp <= ak) {
			if (healed_last_turn)
				return IMPOSSIBLE;
			dragon_hp = hd;
			healed_last_turn = 1;
		} else if (n_buffs > 0) {
			ad += b;
			n_buffs--;
			healed_last_turn = 0;
		} else {
			knight_hp -= ad;
			healed_last_turn = 0;
		}
		n++;
		if (knight_hp <= 0)
			return n;
		dragon_hp -= ak;
	}
}

void solve_test_case(
		int case_idx,
		int hd, int ad,
		int hk, int ak,
		int b, int d
) {
	int64_t n = IMPOSSIBLE;
	int n_buffs = 0;
	int n_debuffs = 0;
	if (d > 0) {
		for (int i = 0; i < hk; ++i) {
			int64_t t;
			t = combat_duration(hd, ad, hk, ak, b, d, i, n_buffs);
			if (t < n) {
				n = t;
				n_debuffs = i;
			}
		}
	}
	if (b > 0) {
		for (int i = 0; i < hk; ++i) {
			int64_t t;
			t = combat_duration(hd, ad, hk, ak, b, d, n_debuffs, i);
			if (t < n) {
				n_buffs = i;
				n = t;
			}
		}
	}
	if (d > 0) {
		for (int i = 0; i < ak; ++i) {
			int64_t t;
			t = combat_duration(hd, ad, hk, ak, b, d, i, n_buffs);
			if (t < n)
				n = t;
		}
	} else {
		n = combat_duration(hd, ad, hk, ak, b, d, 0, n_buffs);
	}
	if (n == IMPOSSIBLE)
		printf("Case #%d: IMPOSSIBLE\n", case_idx);
	else
		printf("Case #%d: %ld\n", case_idx, n);
}

int main(void) {
	int n_test_cases;
	scanf("%d", &n_test_cases);
	for (int i = 0; i < n_test_cases; ++i) {
		int hd, ad, hk, ak, b, d;
		scanf("%d%d%d%d%d%d", &hd, &ad, &hk, &ak, &b, &d);
		solve_test_case(i+1, hd, ad, hk, ak, b, d);
	}
	return 0;
}
