#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int sum(int *,int);
bool check(int *,int);
int* next_add(int *,int,int);
int* next(int*,int);

int main() {
	int N = 0, a = 0, b = 0, c = 0;
	cin >> N >> a >> b >> c;
	int* l = new int[N];
	int* usefor = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> l[i];
		usefor[i] = 1;
	}
	int output = INT32_MAX-1;

	while (true)
	{
		usefor = next(usefor,N);
		int summation = sum(usefor, N);
		if (summation == N * 4) break;
		if (check(usefor,N) == false) continue;

		int magic = 0;
		int A = 0, B = 0, C = 0;
		for (int i = 0; i < N; i++)
		{
			switch (usefor[i])
			{
			case 1:
				if (A != 0) magic = magic + 10;
				A += l[i];
				break;
			case 2:
				if (B != 0) magic = magic + 10;
				B += l[i];
				break;
			case 3:
				if (C != 0) magic=magic+10;
				C += l[i];
				break;

			}
		}
		magic += abs(A - a) + abs(B - b) + abs(C - c);
		if (magic < output) output = magic;



	}

	cout << output << endl;
	return 0;
}


int sum(int l[],int n)
{
	int len = n;
	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum += l[i];
	}
	return sum;
}


bool check(int l[],int n)
{
	bool one = false, two = false, three = false;

	int len = n;
	
	for (int i = 0; i < len; i++)
	{
		switch (l[i])
		{
		case 1:
			one = true;
			break;
		case 2:
			two = true;
			break;
		case 3:
			three = true;
			break;
		}
	}
	return one && two && three;
}

int* next_add(int l[], int n)
{
	if (l[n] == 4) {
		l[n] = 1;
		return next_add(l, n - 1);
	}
	else
	{
		l[n] = l[n] + 1;
		return l;
	}
}

int* next(int l[],int n)
{
	int len = n;
	return next_add(l, len - 1);
}