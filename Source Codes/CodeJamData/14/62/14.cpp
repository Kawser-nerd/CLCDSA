#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std; 

typedef long long ll; 
typedef pair<int, int> pii;

#define INF 1000000000
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

int t, teste, n;
unsigned long long fac[20];

int temp2[20][8000];
int numbers[8000];
int temp[20][8000];

unsigned long long proc(int n, int steps) {
	if (n == 0) return fac[steps];

	bool needs_step = false;
	unsigned long long ans = 0;
	int n1 = -1;
	int n2 = -1;

	for (int i = 0; i < (1<<n); i+=2) {
		if (numbers[i] / 2 == numbers[i+1] / 2) {
			temp2[n][i/2] = numbers[i]/2;
			if (numbers[i] > numbers[i+1]) {
				if (needs_step) return 0;
				needs_step = true;
			}
		}

		else {
			if (n1 == -1) n1 = i;
			else if (n2 == -1) n2 = i;
			else return 0;
		}
	}

	if (n1 != -1 && needs_step) return 0;

	for (int i = 0; i < (1<<n); i++) {
		temp[n][i] = numbers[i];
	}

	if (n1 == -1) {
		for (int i = 0; i < (1<<(n-1)); i++) numbers[i] = temp2[n][i];
		ans = proc(n-1, steps + needs_step);
	}

	else if (numbers[n1] / 2 == numbers[n2] / 2) {
		if (numbers[n2] < numbers[n1]) swap(n1, n2);

		if (numbers[n1+1] > numbers[n2+1]) return 0;

		temp2[n][n1/2] = numbers[n1]/2;
		temp2[n][n2/2] = numbers[n1+1]/2;

		for (int i = 0; i < (1<<(n-1)); i++) numbers[i] = temp2[n][i];
		ans = proc(n-1, steps+1);	
	}

	else {
		if (numbers[n1] > numbers[n2+1] || numbers[n2] > numbers[n1+1]) return 0;

		temp2[n][n1/2] = numbers[n1]/2;
		temp2[n][n2/2] = numbers[n2]/2;

		for (int i = 0; i < (1<<(n-1)); i++) numbers[i] = temp2[n][i];
		ans += proc(n-1, steps+1);

		swap(temp2[n][n1/2], temp2[n][n2/2]);
		for (int i = 0; i < (1<<(n-1)); i++) numbers[i] = temp2[n][i];
		ans += proc(n-1, steps+1);
	}

	for (int i = 0; i < (1<<n); i++) {
		numbers[i] = temp[n][i];
	}

	return ans;
}

int main() {
	fac[0] = 1;
	for (int i = 1; i <= 15; i++) fac[i] = fac[i-1] * i;

	for (scanf("%d", &t); t; t--) {
		printf("Case #%d: ", ++teste);
		scanf("%d", &n);

		for (int i = 0; i < (1<<n); i++) {
			scanf("%d", &numbers[i]);
			numbers[i]--;
		}

		printf("%llu\n", proc(n, 0));
	}

    return 0;
}