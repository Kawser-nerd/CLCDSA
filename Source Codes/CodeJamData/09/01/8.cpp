#include <iostream>
#include <string>
using namespace std;

string words[5001];

int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);

	int L, D, N;
	cin >> L >> D >> N;

	for (int i = 0; i < D; i++)	
		cin >> words[i];

	for (int i = 0; i < N; i++)
	{
		bool ok[15][28] = {0};

		string patt; cin >> patt;
		int cur =0;
		for (int j = 0; j < patt.size(); j++)
			if (patt[j] == '(')
			{
				j++;
				while (patt[j] != ')')
				{
					ok[cur][patt[j]-'a'] = true;
					j++;
				}
				cur++;
			}
			else
				ok[cur++][patt[j]-'a'] = true;
				
		int ans = 0;
		for (int j = 0; j < D; j++)
		{
			bool co = true;
			for (int k = 0; k < L; k++)
				if (!ok[k][words[j][k]-'a'])
					co = false;
			ans += co;
		}
		printf("Case #%d: %d\n", i+1, ans);
	}
}