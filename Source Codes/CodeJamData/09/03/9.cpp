#include <cstdio>
#include <iostream>
#include <sstream>

using namespace std;

int T;
string s = "welcome to code jam";
int table[505][25];

int main()
{
	string str;
	char tmp[1005];

	fgets(tmp, 1000, stdin); str = tmp;
	istringstream sin(str); sin >> T;
	
	for (int Q = 1; Q <= T; ++Q)
	{
		fgets(tmp, 1000, stdin); str = tmp;
		memset(table, 0, sizeof(table));

		for (int i = 0; i < str.size(); ++i)
		{
			for (int j = 0; j < s.size(); ++j)
			{
				if (i != 0) table[i][j] = table[i - 1][j];
				if (str[i] == s[j])
				{
					if (j == 0) table[i][j]++;
					else if (i > 0) table[i][j] += table[i - 1][j - 1];
				}
				table[i][j] %= 10000;
			}
		}

		printf("Case #%d: %04d\n", Q, table[str.size() - 1][s.size() - 1]);
	}
}