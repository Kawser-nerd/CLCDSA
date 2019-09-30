#include<stdio.h>

int TEN[10];

inline bool good(int x, int len) {
	long long xx = x, rx = 0;
	for(rx = 0; x > 0; x /= 10)
		rx = rx*10 + x%10;
	if(!(len&1)) xx = xx*TEN[len>>1] + rx;
	else xx = xx*TEN[len>>1] + rx%TEN[len>>1];
	xx *= xx;
	int l = 0;
	char s[16];
	for(; xx > 0; xx /= 10, ++l) s[l] = xx%10;
	for(int i = 0; i < l-i-1; ++i)
		if(s[i] != s[l-i-1]) return false;
	return true;
}

inline void print(int x, int len) {
	int _x = x;
	long long xx = x, rx = 0;
	for(rx = 0; x > 0; x /= 10)
		rx = rx*10 + x%10;
	if(!(len&1)) xx = xx*TEN[len>>1] + rx;
	else xx = xx*TEN[len>>1] + rx%TEN[len>>1];
	//printf("%4d\t%7lld\t%14lld\n", _x, xx, xx*xx);
	printf("%lld, ", xx*xx);
}

int main() {
	TEN[0] = 1;
	for(int i = 1; i < 9; ++i) TEN[i] = TEN[i-1] * 10;
	for(int len = 1; len <= 8; ++len) {
		int hf = len - (len>>1);
		for(int i = TEN[hf-1]; i < TEN[hf]; ++i)
			if(good(i, len)) print(i, len);
	}
	puts("");
}
