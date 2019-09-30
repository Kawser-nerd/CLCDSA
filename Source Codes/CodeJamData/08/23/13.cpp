#include <iostream>
#include <cassert>
#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std;

inline int chld1(int x)
{
	return 2*x;
}
inline int chld2(int x)
{
	return 2*x+1;
}
inline int parent(int x)
{
	return x/2;
}

const int SIZE = 1024 * 1024;
int Left[SIZE];
int res[SIZE];

void insert(int x)
{
	int pos = 1;
	int lower = 1, upper = SIZE+1;
	while (pos < SIZE)
	{
		int mid = (lower + upper) / 2;
		if (x < mid)
		{
			Left[pos]++;
			upper = mid;
			pos = chld1(pos);
		}
		else
		{
			lower = mid;
			pos = chld2(pos);
		}
	}
}

int query(int rank)
{
	int pos = 1;
	while (pos < SIZE)
	{
		if (Left[pos] <= rank)
		{
			rank -= Left[pos];
			pos = chld2(pos);
		}
		else
		{
			Left[pos]--;
			pos = chld1(pos);
		}
	}
	return pos - SIZE;
}

int main()
{
	int kases, kase = 0;
	for (cin >> kases; kases; kases--)
	{
		int K;
		cin >> K;
		memset(Left, 0, sizeof(Left));
		for (int i = 1; i <= K; i++)
			insert(i);

		int pos = 0;
		int size = K;
		for (int i = 1; i <= K; i++)
		{
			pos = (pos + i-1) % size;
			res[query(pos)] = i;
			size--;
		}
/*
		for (int i = 0; i < K; i++)
			cout << res[i] << " ";
		cout << endl;
*/
		int n;
		cin >> n;
		cout << "Case #" << ++kase << ":";
		while (n--)
		{
			int x;
			cin >> x;
			cout << " " << res[x-1];
		}
		cout << endl;
	}
	return 0;
}
