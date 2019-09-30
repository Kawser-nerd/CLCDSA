#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<math.h>
#include<queue>
#include <algorithm>
#include<functional>
#include<cstdlib>
#include<cmath>


#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define CI cin >>
#define CO cout <<
#define E << endl;

using namespace std;

typedef pair<int, int> P;
typedef pair<long, long> LP;
typedef pair<int, P> PP;
typedef pair<long, LP> LPP;

int N;

int dy[] = { 0, 0, 1, -1, 0 };
int dx[] = { 1, -1, 0, 0, 0 };

string name;

int a, b, c, d;

int number[100005] = { 0 };

void input(void) {
	CI N;
	for (int i = 0; i < N; i++) {
		CI number[i];
	}
	return;
}


int main(void) {
	input();
	int xx = 0;
	int before = 0;
	int next = 0;
	long int count = 0;
	int flag = false;
	int temp = 0;
	for (int i = 0;i < N; i++) {
		before = number[i];
		for (int j = i; j < N;j++) {
			xx++;
			next = number[j];
			if (before < next || (before <= next && i == j) ) {
				count += j - i + 1;
			}
			else {
				i += j - i - 1;
				flag = true;
				break;
			}
			if (flag == false)temp  = j - i;
			before = number[j];
		}
		if (flag == false) {
			i += temp;
			temp = 0;
		}
		flag = false;
		
	}

	CO count E

	return 0;
}