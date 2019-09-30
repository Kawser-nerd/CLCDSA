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
struct rec 
{
	rec () {}
	long long num;
	int pos;

	bool operator < (const rec & other) const 
	{
		return num != other.num ? num < other.num : pos > other.pos; 
	}
};

const int MAXN = 1024 * 1024;
int n, m;
long long x, y, z;
long long b [MAXN];
rec a [MAXN];

const long long mod = 1000000007LL;

void gen ()
{
	for (int i = 0 ; i < n; ++ i)
	{
		a[i].num = b[i % m];
		a[i].pos = i + 1;
		b[i % m] = ((x * b[i % m]) % z + (y * (i + 1)) % z) % z;
	}
}

long long cnt [MAXN];

void add (long long pos, long long value)
{
	while (pos <= n)
	{
		 cnt [pos] = (cnt [pos] + value) % mod;
		 pos = pos + pos - (pos & (pos - 1));
	}
}

long long get (long long pos)
{
	long long res = 0;
	while (pos)
	{
		res += cnt [pos];
		res %= mod;
		pos &= pos - 1;
	}
	return res;
}

int main ()
{
	int tests = 0;
	fin >> tests;

	while (tests -- > 0)
	{

		memset (cnt, 0, sizeof (cnt));

		fin >> n >> m >> x >> y >> z;
		for (int i = 0; i < m; ++ i) fin >> b[i];
		gen ();
		sort(a, a + n);

		long long last = a[0].num;
		int number = 2;

		for (int i = 0; i < n; ++ i)
		{
			if (last != a[i].num)
			{
				++ number ;
				last = a[i].num;
			}
			a[i].num = number;
		}

		long long res = 0;
		for (int i = 0; i < n; ++ i)
		{
			long long curr = get (a[i].pos) + 1;
			res = (res + curr) % mod;
			add (a[i].pos, curr);
		}

		static int caseNum = 0;
		fout << "Case #" <<  (++ caseNum) << ": "  << res << endl;
	}

	return 0;
}