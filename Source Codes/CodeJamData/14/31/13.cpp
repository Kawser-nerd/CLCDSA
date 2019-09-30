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

ll gcd(ll A, ll B)
{
	while (B != 0)
	{
		A %= B;
		swap(A, B);
	}
	return A;
}

bool power2(ll N)
{
	if (N == 0) return false;
	while (N % 2 != 1) N /= 2;
	return N == 1;
}

ll P, Q;

ll solve(void)
{
	ll g = gcd(P, Q);
	P /= g;
	Q /= g;


	if (power2(Q) == false) return -1;
	else
	{
		ll result = 1;
		ll temp = Q / 2;
		while (temp > P)
		{
			temp /= 2;
			result++;
		}
		return result;
	}
	
}

void solve_A(void)
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	int T;
	in >> T;

	for (int tt = 1; tt <= T; tt++)
	{
		in >> P;
		in.ignore(1);
		in >> Q;
		ll temp = solve();
		out << "Case #" << tt << ": ";
		if (temp!=-1) out << temp;
		else out << "impossible";
		out << '\n';
	}

	in.close();
	out.close();
}

int main()
{
	solve_A();
	//solve_B();
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