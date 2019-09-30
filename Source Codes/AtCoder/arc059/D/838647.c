#include <stdio.h>
#include <string.h>
#include <inttypes.h>

#define MOD_BY UINT32_C(1000000007)
#define INV2 UINT32_C(500000004)

int N,l;
char s[50000];

#if 0
uint32_t modoru_memo[12000][6000]; /* [??][??] */

uint32_t modoru_search(int pos, int left) {
	uint32_t ret = 0;
	if (left == 1) return pos == 1;
	if (left == 0) return 1;
	if (modoru_memo[pos][left]) return ~modoru_memo[pos][left];

	if (pos == 0) {
		/* ???????????? */
		ret = modoru_search(pos, left - 1);
	} else {
		/* ????? */
		ret = modoru_search(pos - 1, left - 2);
		ret += ret; /* 0????????? */
		if (ret >= MOD_BY) ret -= MOD_BY;
	}
	/* ????? */
	ret += modoru_search(pos + 1, left - 2);
	if (ret >= MOD_BY) ret -= MOD_BY;

	return ~(modoru_memo[pos][left] = ~ret);
}
#endif

uint32_t memo[6000][6000]; /* [??][?????] */

uint32_t search(int pos, int left) {
	uint32_t ret=0;

	if (left == 0) return pos == l;
	if (memo[pos][left])return ~memo[pos][left];

	/* 0???1??? */
	ret = search(pos + 1, left - 1);
	ret += ret;
	if (ret >= MOD_BY) ret -= MOD_BY;
	/* ?????????? */
	ret += search(pos == 0 ? pos : pos - 1, left - 1);
	if (ret >= MOD_BY) ret -= MOD_BY;

	return ~(memo[pos][left] = ~ret);
}

int main(void) {
	uint32_t tmp;
	uint32_t divnum;
	if(scanf("%d%49999s",&N,s)!=2)return 1;
	l=strlen(s);
	/* ??????????? */
	tmp=search(0, N);
	/* ????????????????? */
	divnum=INV2;
	while(l>0) {
		if(l&1)tmp=((uint64_t)tmp*divnum)%MOD_BY;
		divnum=((uint64_t)divnum*divnum)%MOD_BY;
		l>>=1;
	}
	printf("%"PRIu32"\n", tmp);
	return 0;
}