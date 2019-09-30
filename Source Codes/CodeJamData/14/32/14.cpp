#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <iomanip>
#include <cassert>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

bool is_aaa(const string& s, char c)
{
	for (int i = 0; i < (int)s.size(); i++)
	{
		if (s[i] != c) return false;
	}
	return true;
}

bool is_aax(const string& s, char c)
{
	return s[0] == c;
}

bool is_yaa(const string& s, char c)
{
	return s[(int)s.size() - 1] == c;
}

bool is_uav(const string& s, char c)
{
	for (int i = 0; i < (int)s.size(); i++)
	{
		if (s[i] == c) return true;
	}
	return false;
}

int fragment_count(const string& s, char c)
{
	int result = 0;
	int n = (int)s.size();
	int i = 0;
	while (i < n)
	{
		if (s[i] != c) i++;
		else
		{
			int j = i;
			while (j + 1 < n && s[j + 1] == c) j++;
			result++;
			i = j + 1;
		}
	}
	return result;
}

const int MAXN = 109;
int N;
string s[MAXN];
vector<string> pieces;

const ll MOD = 1000000007;
ll fact[MAXN];



ll solve(void)
{
	pieces.clear();
	for (int i = 0; i < N; i++) pieces.push_back(s[i]);
	ll result = 1;

	for (char c = 'a'; c <= 'z'; c++)
	{
		vector<string> aaa;
		vector<string> aax;
		vector<string> yaa;
		vector<string> uav;
		vector<string> other;

		for (int i = 0; i < pieces.size(); i++)
		{
			if (is_aaa(pieces[i], c)) aaa.push_back(pieces[i]);
			else if (is_aax(pieces[i], c)) aax.push_back(pieces[i]);
			else if (is_yaa(pieces[i], c)) yaa.push_back(pieces[i]);
			else if (is_uav(pieces[i], c)) uav.push_back(pieces[i]);
			else other.push_back(pieces[i]);
		}

		if (uav.size() != 0)
		{
			if (aaa.size() == 0 && aax.size() == 0 && yaa.size() == 0 && uav.size()==1 && fragment_count(uav[0], c)==1)
			{
				;
			}
			else return 0LL;
		}
		else
		{
			if (aaa.size() == 0 && aax.size() == 0 && yaa.size() == 0)
			{
				; // no constraints at all
			}
			else
			{
				if (yaa.size() <= 1 && aax.size() <= 1)
				{
					if (yaa.size() == 1)
					{
						if (fragment_count(yaa[0], c) > 1) return 0LL;
					}
					if (aax.size() == 1)
					{
						if (fragment_count(aax[0], c) > 1) return 0LL;
					}

					result *= fact[aaa.size()];
					result %= MOD;

					pieces = other;
					string new_piece;
					if (yaa.size() != 0) new_piece += yaa[0];
					for (int i = 0; i < aaa.size(); i++) new_piece += aaa[i];
					if (aax.size() != 0) new_piece += aax[0];
					pieces.push_back(new_piece);
				}
				else return 0LL;
			}
		}
	}

	result *= fact[pieces.size()];
	result %= MOD;
	return result;
}

void solve_B(void)
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	int T;
	in >> T;

	fact[0] = 1LL;
	for (int i = 1; i < MAXN; i++) fact[i] = (fact[i - 1] * i) % MOD;

	for (int tt = 1; tt <= T; tt++)
	{
		for (int i = 0; i < MAXN; i++) s[i] = "";
		in >> N;
		for (int i = 0; i < N; i++) in >> s[i];
		ll temp = solve();
		out << "Case #" << tt << ": ";
		out << temp;
		out << '\n';
	}

	in.close();
	out.close();
}

int main()
{
	//solve_A();
	solve_B();
	//solve_C();
	return 0;
}

void solve_(void)
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	int T;
	in >> T;

	for (int tt = 1; tt <= T; tt++)
	{
		out << "Case #" << tt << ": ";
	}

	in.close();
	out.close();
}