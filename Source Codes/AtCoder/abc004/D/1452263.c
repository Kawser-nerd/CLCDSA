#include<stdio.h>
#include<string.h>
#include<math.h>

const int INF = 1 << 30;
const int POS[3] = {-100, 0, 100};

int R[4], dp[2000][1000], i;

int rec(int idx, int pos)
{
	int ret, i, sub;
	if(pos == R[3])          return(0);
	if(idx >= 1000)          return(INF);
	if(~dp[idx + 1000][pos]) return(dp[idx + 1000][pos]);
	ret = rec(idx + 1, pos);
	for(i = 2; i >= 0; i--) {
		if(R[i] <= pos) {
			sub = rec(idx + 1, pos + 1) + fabs(POS[i] - idx);
			if(ret > sub) ret = sub;
			break;
		}
	}
	dp[idx + 1000][pos] = ret;
	return(ret);
}

int main()
{
	memset(dp, -1, sizeof(dp));
	
  for(i = 1; i < 4; i++) {
		scanf("%d", &R[i]);
		R[i] += R[i - 1];
	}
	printf("%d\n", rec(-1000, 0));
	return(0);
} ./Main.c: In function ‘main’:
./Main.c:33:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &R[i]);
   ^