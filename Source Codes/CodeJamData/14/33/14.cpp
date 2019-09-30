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

inline int cost(int L, int R, int W)
{
	return L + R + 2 * W - 4;
}



int area(int L, int R, int W, int N, int M)
{
	//if (L < R) swap(L, R);
	int max_gain = (W - 1) * 2;
	if (L > R + max_gain) return -1;
	
	int curr_H = L;
	int result = curr_H;

	for (int w = 2; w <= W; w++)
	{
		int max_gain_poss = (W - w) * 2;
		if (curr_H + 2 <= N && curr_H+2 <= R + max_gain_poss)
		{
			curr_H += 2;
		}
		else if (curr_H + 1 <= N && curr_H + 1 <= R + max_gain_poss)
		{
			curr_H += 1;
		}
		else if (curr_H <= R + max_gain_poss)
		{
			curr_H = curr_H;
		}
		else if (curr_H - 1 <= R + max_gain_poss)
		{
			curr_H -= 1;
		}
		else
		{
			curr_H -= 2;
		}
		result += curr_H;
	}

	return result;
}

const int INF = 1000 * 1000 * 100;

int solve(int N, int M, int K)
{
	int result = INF;
	if (K <= max(N, M)) result = min(result, K);
	
	//cout << "Input data: " <<  N << ' ' << M << ' ' << K << endl;

	for (int L = 1; L <= N; L++)
	{
		for (int R = 1; R <= L; R++)
		//for (int R = max(L - 2, 1); R <= L; R++)
		{
			for (int W = 2; W <= M; W++)
			{
				int ar = area(L, R, W, N, M);
				if (ar >= K)
				{
					int new_cost = cost(L, R, W);
					if (new_cost < result)
					{
						result = min(result, new_cost);
						//cout << L << ' ' << R << ' ' << W << endl;
					}
				}
			}
		}
	}

	//cout << "------------------\n";
	//cin.get();

	return result;
}

int solve_heuristic(int N, int M, int K)
{
	int result = INF;
	if (K <= max(N, M)) result = min(result, K);

	//cout << "Input data: " <<  N << ' ' << M << ' ' << K << endl;

	for (int L = 1; L <= N; L++)
	{
		//for (int R = 1; R <= L; R++)
		for (int R = max(L - 2, 1); R <= L; R++)
		{
			for (int W = 2; W <= M; W++)
			{
				int new_cost = cost(L, R, W);
				if (new_cost < result)
				{
					int ar = area(L, R, W, N, M);
					if (ar >= K)
					{
						result = new_cost;
					}
				}
			}
		}
	}

	//cout << "------------------\n";
	//cin.get();

	return result;
}

void solve_C(void)
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	int T;
	in >> T;

	for (int tt = 1; tt <= T; tt++)
	{
		int N, M, K;
		in >> N >> M >> K;
		int temp = solve(N, M, K);
		//int temp = solve_heuristic(N, M, K);
		out << "Case #" << tt << ": ";
		out << temp;
		out << '\n';
		//if (temp != solve_heuristic(N, M, K)) cout << N << ", " << M << ", " << K << endl;
	}

	in.close();
	
	out.close();
}


int main()
{
	//solve_A();
	//solve_B();
	solve_C();
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