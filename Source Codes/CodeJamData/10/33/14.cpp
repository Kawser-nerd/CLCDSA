#include <cstdio>

void OpenFiles()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

int m, n;
int field[512][512];

int Max(int a, int b)
{
	return a > b ? a : b;
}

int Number(char t)
{
	if (t >= '0' && t <= '9') return t-'0';
	else return t - 'A' + 10;
}

void ScanTest()
{
	scanf("%d%d\n", &m, &n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j+=4)
		{
			char c;
			scanf("%c", &c);
			int num = Number(c);
			field[i][j+0] = ((num & 8) != 0) ? 1 : 0;
			field[i][j+1] = ((num & 4) != 0) ? 1 : 0;
			field[i][j+2] = ((num & 2) != 0) ? 1 : 0;
			field[i][j+3] = ((num & 1) != 0) ? 1 : 0;
		}
		scanf("\n");
	}
}

int len[512][512];
int res[513];

void InitRes()
{
	for (int i = 0; i <= 512; i++)
		res[i] = 0;
}

void InitLen()
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			len[i][j] = 1;
	for (int l = 2;; l++)
	{
		bool flag = false;
		
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (len[i][j] == l-1 && i+l <= m && j+l <= n)
				{
					int il = i+l-1;
					int jl = j+l-1;
					bool res = field[il][j] != field[il-1][j];
					for (int i1 = i; i1 <= il-1 && res; i1++)
						res = res && (field[i1][jl] != field[i1+1][jl]);
					for (int j1 = j; j1 <= jl-1 && res; j1++)
						res = res && (field[il][j1] != field[il][j1+1]);
					if (res)
					{
						len[i][j] = l;
						flag = true;
					}
				}

		if (!flag)
			break;
	}
}

bool CanCut(int i0, int j0, int l)
{
	for (int i = i0; i < i0+l; i++)
		for (int j = j0; j < j0+l; j++)
			if (field[i][j] == -1)
				return false;
	return true;
}

void Fill(int i0, int j0, int l)
{
	for (int i = i0; i < i0+l; i++)
		for (int j = j0; j < j0+l; j++)
			field[i][j] = -1;
}

void Solve(int testId)
{
	ScanTest();
	InitLen();	
	InitRes();

	for (int l = Max(m, n); l > 0; l--)
	{
		for (int i = 0; i+l <= m; i++)
			for (int j = 0; j+l <= n; j++)
				if (len[i][j] >= l && CanCut(i,j,l))
				{
					Fill(i,j,l);
					res[l]++;
				}
	}

	int chessSizes = 0;
	for (int i = 1; i <= 512; i++)
		if (res[i] != 0)
			chessSizes++;
	printf("Case #%d: %d\n", testId, chessSizes);
	for (int i = 512; i >= 1; i--)
		if (res[i] != 0)
			printf("%d %d\n", i, res[i]);
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