#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

const int MAXN = 50;

long long cnt [MAXN][7][7][7][7];

int main ()
{
	int tests = 0;
	fin >> tests;

	while (tests -- > 0)
	{

		string s;
		fin >> s;
		int n = s.length();

		memset (cnt, 0, sizeof (cnt));

		cnt [0][0][0][0][0] = 1;

		for (int pos = 0; pos < n; ++ pos)
			for (int p2 = 0; p2 < 2; ++ p2)
				for (int p3 = 0; p3 < 3; ++ p3)
					for (int p5 = 0; p5 < 5; ++ p5)
						for (int p7 = 0; p7 < 7; ++ p7)
							if (cnt [pos][p2][p3][p5][p7] > 0)
							{
								int mods [4] = {0, 0, 0, 0};
								int v [4];
							
								for (int i = pos; i < n; ++ i)
								{
									mods [0] = (mods[0] * 10 + s[i] - '0') % 2;
									mods [1] = (mods[1] * 10 + s[i] - '0') % 3;
									mods [2] = (mods[2] * 10 + s[i] - '0') % 5;
									mods [3] = (mods[3] * 10 + s[i] - '0') % 7;

									v[0] = (mods [0] + p2) % 2;
									v[1] = (mods [1] + p3) % 3;
									v[2] = (mods [2] + p5) % 5;
									v[3] = (mods [3] + p7) % 7;

									cnt [i + 1][v[0]][v[1]][v[2]][v[3]] += cnt [pos][p2][p3][p5][p7];
								}
								memset (mods, 0, sizeof (mods));
								if (pos == 0) continue ;
								
								for (int i = pos; i < n; ++ i)
								{
									mods [0] = (mods[0] * 10 + s[i] - '0') % 2;
									mods [1] = (mods[1] * 10 + s[i] - '0') % 3;
									mods [2] = (mods[2] * 10 + s[i] - '0') % 5;
									mods [3] = (mods[3] * 10 + s[i] - '0') % 7;

									v[0] = (( - mods [0] + p2) % 2 + 2) % 2;
									v[1] = (( - mods [1] + p3) % 3 + 3) % 3;
									v[2] = (( - mods [2] + p5) % 5 + 5) % 5;
									v[3] = (( - mods [3] + p7) % 7 + 7) % 7;

									cnt [i + 1][v[0]][v[1]][v[2]][v[3]] += cnt [pos][p2][p3][p5][p7];
								}
							}

		long long res = 0;

		for (int p1 = 0; p1 < 7; ++ p1)
			for (int p2 = 0; p2 < 7; ++ p2)
				for (int p3 = 0; p3 < 7; ++ p3)
					for (int p4 = 0; p4 < 7; ++ p4)
					{
						if (p1 == 0 || p2 == 0 || p3 == 0 || p4 == 0)
							res += cnt [n][p1][p2][p3][p4];
					}
		static int caseNum = 0;
		fout << "Case #" <<  (++ caseNum) << ": " << res << endl;
	}

	return 0;
}