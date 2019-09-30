#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
//#include <utility>
//#include <set>
//#include <map>
//#include <queue>
using namespace std;

#define mset(A,B) memset(A,B,sizeof(A));
#define mcpy(A,B) memcpy(A,B,sizeof(B));
typedef long long ll;
typedef long double ld;
typedef vector<int> vint;
//typedef vector<string> vstr;
#define FI(I,L,U) for (int I=L;I<U;I++)
#define sqr(x) ((x)*(x))

int parse(const char* s)
{
	return ((s[0]-'0')*10+s[1]-'0')*60+(s[3]-'0')*10+s[4]-'0';
}

int calc(int n1, int t1[], int n2, int t2[])
{
	sort(t1, t1+n1);
	sort(t2, t2+n2);
	int i = 0;
	int ret = 0;
	for (int j = 0; j < n2; j++)
	{
		if (i < n1 && t1[i] <= t2[j])
			i++;
		else
			ret++;
	}
	return ret;
}

int main()
{
	int tcase = 0;
	ifstream fin("z.in");
	ofstream fout("z.out");
	fin >> tcase;
	for (int tind = 1; tind <= tcase; tind++)
	{
		string line;
		int t, na, nb;
		fin >> t;
		fin >> na >> nb;
		getline(fin, line);
		int i,j;
		int sa[110], ea[110];
		int sb[110], eb[110];
		for (i = 0; i < na; i++)
		{
			getline(fin, line);
			sa[i] = parse(line.c_str());
			ea[i] = parse(line.c_str()+6) + t;
		}
		for (i = 0; i < nb; i++)
		{
			getline(fin, line);
			sb[i] = parse(line.c_str());
			eb[i] = parse(line.c_str()+6) + t;
		}
		int ans1, ans2;
		ans1 = calc(nb, eb, na, sa);
		ans2 = calc(na, ea, nb, sb);
		fout << "Case #" << tind << ": " << ans1 << ' ' << ans2 << endl;
	}
	return 0;
}
