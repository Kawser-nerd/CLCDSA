#include <iostream>
#include <string.h>
#include <cstring>
#include <string>

using namespace std;

int n;
char s[110][110];
int w[110], l[110];
double owp[110], wp[110], oowp[110];

void solve(int test)
{
	scanf("%d\n", &n);
	for (int i = 0; i < n; i ++)
		gets(s[i]);

	for (int i = 0; i < n; i ++)
		w[i] = l[i] = 0;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++)
			if (s[i][j] == '1') w[i] ++; else 
				if (s[i][j] == '0') l[i] ++;

	for (int i = 0; i < n; i ++)
		wp[i] = (double)(w[i]) / (double)(w[i] + l[i]);

	for (int i = 0; i < n; i ++)
	{
		owp[i] = 0.0;
		double op = 0.0;
		for (int j = 0; j < n; j ++)
			if (s[i][j] != '.')
				owp[i] += (double)(w[j] - s[j][i] + '0') / (double)(w[j] + l[j] - 1), op += 1.0;
		owp[i] /= op;
	}

	for (int i = 0; i < n; i ++)
	{
		oowp[i] = 0.0;
		double op = 0.0;
		for (int j = 0; j < n; j ++)
			if (s[i][j] != '.')
				oowp[i] += owp[j], op += 1.0;
		oowp[i] /= op;
	}

	printf("Case #%d:\n", test);
	for (int i = 0; i < n; i ++)
		printf("%.10lf\n", 0.25 * wp[i] + 0.5 * owp[i] + 0.25 * oowp[i]);
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int test;
	scanf("%d\n", &test);
	for (int i = 1; i <= test; i ++)
		solve(i);
	return 0;
}