#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<cstdint>
using u32 = ::std::uint_least32_t;

constexpr u32 BITWIDTH = 5;
struct BitFenwickTree {
	::std::vector<u32> c;
	::std::vector<u32> bitvec;
	u32 base;

	BitFenwickTree(const u32 len) :
		c(len + 0x3F >> BITWIDTH, 0), bitvec(len + 0x1F >> BITWIDTH, 0) {
		base = 1;
		while (base < c.size() - 1)
			base <<= 1;
		base >>= 1;
	}

	bool get(const u32 index)const {
		return bitvec[index >> BITWIDTH] & 1U << (index & 0x1F);
	}

	u32 select(u32 rank)const {
		u32 idx = base;
		u32 k = idx >> 1;
		while (k) {
			if (idx < c.size() && c[idx] <= rank) {
				rank -= c[idx];
				idx += k;
			}
			else {
				idx -= k;
			}
			k >>= 1;
		}
		if (c[idx] <= rank) {
			rank -= c[idx];
		}
		else {
			--idx;
		}
		return idx << BITWIDTH | bit_select(bitvec[idx], rank);
	}

	void flip(const u32 index) {
		bitvec[index >> BITWIDTH] ^= 1U << (index & 0x1F);
		u32 cidx = (index >> BITWIDTH) + 1;
		if (get(index)) {
			while (cidx < c.size()) {
				++c[cidx];
				cidx += cidx & ~cidx + 1;
			}
		}
		else {
			while (cidx < c.size()) {
				--c[cidx];
				cidx += cidx & ~cidx + 1;
			}
		}
	}

	static u32 bit_select(const u32 b1, u32 rank) {
		const u32 b2 = (b1 & 0x55555555U) + (b1 >> 1 & 0x55555555U);
		const u32 b4 = (b2 & 0x33333333U) + (b2 >> 2 & 0x33333333U);
		const u32 b8 = b4 + (b4 >> 4) & 0x0F0F0F0FU;
		const u32 b16 = b8 + (b8 >> 8) & 0x00FF00FFU;
		u32 idx = 0;
		if ((b16&0x1F) <= rank) {
			rank -= b16&0x1F;
			idx |= 0x10;
		}
		if ((b8 >> idx & 0xF) <= rank) {
			rank -= b8 >> idx & 0xF;
			idx |= 0x8;
		}
		if ((b4 >> idx & 0x7) <= rank) {
			rank -= b4 >> idx & 0x7;
			idx |= 0x4;
		}
		if ((b2 >> idx & 0x3) <= rank) {
			rank -= b2 >> idx & 0x3;
			idx |= 0x2;
		}
		if ((b1 >> idx & 0x1) <= rank) {
			++idx;
		}
		return idx;
	}
};

#include<cstdio>

int main() {
	constexpr u32 N = 200000;
	u32 q;
	scanf("%u", &q);
	BitFenwickTree bst(N + 1);
	u32 t, x;
	while (q--) {
		scanf("%u%u", &t, &x);
		if (t == 1) {
			bst.flip(x);
		}
		else {
			u32 ans = bst.select(x - 1);
			printf("%u\n", ans);
			bst.flip(ans);
		}
	}
	return 0;
} ./Main.cpp:13:9: warning: operator '>>' has lower precedence than '+'; '+' will be evaluated first [-Wshift-op-parentheses]
                c(len + 0x3F >> BITWIDTH, 0), bitvec(len + 0x1F >> BITWIDTH, 0) {
                  ~~~~^~~~~~ ~~
./Main.cpp:13:9: note: place parentheses around the '+' expression to silence this warning
                c(len + 0x3F >> BITWIDTH, 0), bitvec(len + 0x1F >> BITWIDTH, 0) {
                      ^
                  (         )
./Main.cpp:13:44: warning: operator '>>' has lower precedence than '+'; '+' will be evaluated first [-Wshift-op-parentheses]
                c(len + 0x3F >> BITWIDTH, 0), bitvec(len + 0x1F >> BITWIDTH, 0) {
                                                     ~~~~^~~~~~ ~~
./Main.cpp:13:44: note: place parentheses around the '+' expression to silence this warning
                c(len + 0x3F >> BITWIDTH, 0), bitvec(len + 0x1F >> BITWIDTH, 0) {
                                                         ^
                                                    ...