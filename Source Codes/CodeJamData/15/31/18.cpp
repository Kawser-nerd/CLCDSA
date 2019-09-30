//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

typedef unsigned long long ul;
typedef long long ll;

int R, C, W;

int solve_1()
{
    return C/W;
}

int solve_2()
{
    int guesses=C/W;
    int last_pos = -1+W*guesses;

    if(last_pos == C-1)
	{
        return guesses+W-1;
	}
	else return guesses+W;
}

int solve()
{
    return (R-1)*solve_1() + solve_2();
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    for(int t=1; t<=T; t++)
	{

		cin >> R >> C >> W;
		cout << "Case #" << t << ": ";
		cout << solve();
		cout << "\n";
	}

	return 0;
}
