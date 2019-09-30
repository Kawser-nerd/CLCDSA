#include <cstdio>

void OpenFiles()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

int a[2000], b[2000];
int n;

bool Crossed(int i, int j)
{
	if (a[i] < a[j] && b[i] > b[j])
		return true;
	if (a[i] > a[j] && b[i] < b[j])
		return true;
	return false;
}

void Solve(int testId)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &a[i], &b[i]);

	int ans = 0;

	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++)
			if (Crossed(i, j))
				ans++;

	printf("Case #%d: %d\n", testId, ans);
}

int main()
{
	OpenFiles();
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		Solve(i+1);
	}

	return 0;
}