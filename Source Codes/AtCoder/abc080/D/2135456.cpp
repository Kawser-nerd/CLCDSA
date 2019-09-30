#include<cstdio>
int tt[200002];
int sm[200002];
int s[100000];
int t[100000];
int c[100000];
int main()
{
	int i, j;
	int mx = 0;
	int aaaa = 0;
	int N;
	int C;

	scanf("%d%d", &N, &C);

	for(i=0;i<N;i++)
	{
		scanf("%d%d%d", &s[i], &t[i], &c[i]);
	}
	for(j=0;j<200002;j++) sm[j] = 0;

	for(i=0; i<=C; i++)
	{
		for(j=0;j<200002;j++) tt[j] = 0;
		for(j=0;j<N;j++) {
			if(c[j]==i) {
				tt[s[j]*2-1]++;
				tt[t[j]*2]--;
			}
		}
		for(j=1;j<200002;j++) {
			tt[j] = tt[j] + tt[j-1];
		}
		for(j=0;j<200002;j++) {
			if(tt[j]>0) {
				sm[j]++;
			}
		}
		aaaa +=1;
	}

	for(j=1;j<200002;j++) {
		if(sm[j]>mx) mx = sm[j];
	}
	printf("%d\n", mx);
	return 0;
}