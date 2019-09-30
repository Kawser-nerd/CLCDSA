#include <iostream>
#include <fstream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>

using namespace std;

string n;

void Load()
{
	cin >> n;
}

int chave[10];

bool Can(int pos)
{
	int i;
	int sum = 0;
	for (i = 1; i <= 9; i++) sum += chave[i];
	if (n.length() - pos - 1 >= sum) return true;
	return false;
}

void Restore(int i)
{
	int j;
	for (i++; i < n.length(); i++)
	{
		for (j = '0'; j <= '9'; j++)
		{
			if (j == '0' || chave[j - '0'] > 0)
			{
				n[i] = j;
				chave[j - '0']--;
				if (Can(i))
				{
					break;
				}
				chave[j - '0']++;
			}
		}
	}
	printf("%s", n.c_str());
}

void Solve()
{
	int i, j;
	memset(chave, 0, sizeof(chave));
	for (i = n.length() - 1; i >= 0; i--)
	{
		chave[n[i] - '0']++;
		for (j = n[i] + 1; j <= '9'; j++)
		{
			if (j == '0' || chave[j - '0'] > 0)
			{
				n[i] = j;
				chave[j - '0']--;
				if (Can(i))
				{
					Restore(i);
					return;
				}
				chave[j - '0']++;
			}
		}
	}
	// add
	n = '0' + n;
	for (i = '1'; i <= '9'; i++)
	{
		if (chave[i - '0'] > 0)
		{
			n[0] = i;
			chave[i - '0']--;
			if (Can(0))
			{
				Restore(0);
				return;
			}
			chave[i - '0']++;
		}
	}
	cout << "botva!!!";
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int nt, it;
	scanf("%d", &nt);
	for (it = 0; it < nt; it++)
	{
		printf("Case #%d: ", it + 1);
		Load();
		Solve();
		printf("\n");
	}
	return 0;
}