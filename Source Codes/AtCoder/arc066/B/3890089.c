//#include "pch.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define llong long long
#define fr(i,l,r) for(i=(l);i<(r);i++)
#define min(p,q) ((p)<(q)?(p):(q))
#define max(p,q) ((p)>(q)?(p):(q))
#define INF 1000000000000//10^12

llong ketamax[80];
llong sanjo[80];
llong nijo[80];
int roop=0;
int dp[100][5];

int init(int x, int y) {
	int i, j;
	for (i = 1;i <= x;i++) {
		for (j = 0;j < y;j++) {
			dp[i][j] = 0;
		}
	}
	return 0;
}

llong rec(llong keta, llong sum) {

	int r;
	int i;
	llong ret = 0;

	roop++;
	//printf("keta=%lld,sum=%lld,roop=%d\n",keta,sum,roop);

		//??????????????

	if (sum >= ketamax[keta]) {
		return sanjo[keta];
	}else if(sum==0){
		return 1;
	}else if (keta == 1) {
		return sum+1;
	}

	//??????????????roop??????

	//x=(int)n[keta]-'0';

	r = min(2,sum/nijo[keta]);

	if (dp[keta][r] > 0) {
		return dp[keta][r];
	}


	//???(rec())???
	for (i = 0;i <= r;i++) {
		ret = ret + rec(keta - 1, sum - i*nijo[keta]);
		ret = ret % 1000000007;
	}

	dp[keta][r] = ret;
	return ret;
}

int main(void)
{
	//?????
	llong n;

	//??????
	int i, j, k, l;
	int flag = 0;
	llong int ans = 0;
	int count = 0;
	llong int temp, temp1, temp2;
	int max, min;
	int len;
	int sum = 0;
	int under, upper, middle;
	int dummy;

	//????????
	scanf("%lld", &n);
	//scanf_s("%lld", &n);

	//	printf("n?%d??\n", n);
	//	printf("??????????\n");
	//?????

	temp = 1;
	count = 1;
	ketamax[1] = 2;
	nijo[1] = 1;
	sanjo[1] = 3;
	
	while (temp < n) {
		temp = temp * 2;
		count++;
		ketamax[count] = temp*4-2;
		nijo[count] = nijo[count - 1] * 2;
	}

	for (i = 1;i <= count;i++) {
		if (i == 1) {
			sanjo[i] = 3;
		}
		else {
			sanjo[i] = (sanjo[i - 1] * 3) % 1000000007;
		}
	}

	init(80, 4);
	ans = rec(count, n);

	//	printf("??????\n");
	//??

	printf("%lld", ans);


	//	printf("???????\n");

	return 0;

} ./Main.c: In function ‘main’:
./Main.c:87:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &n);
  ^