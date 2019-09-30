#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<map>
#include<math.h>
#include<iomanip>

#define REP(i,n) for(ll i = 0; i < (ll)n; i++)
#define FOR(i,a,b) for (ll i=(a);i<(ll)b; i++)
#define PRINT(x) std::cout << x << std::endl;

typedef long long ll;

using namespace std;

int main(void) {
	char X;
	cin >> X;
	string ab = "ABCDE";

	printf("%d\n", ab.find(X) + 1);

ProgramEndPointLabel:;

	system("pause");

	return 0;
} ./Main.cpp:24:17: warning: format specifies type 'int' but the argument has type 'unsigned long' [-Wformat]
        printf("%d\n", ab.find(X) + 1);
                ~~     ^~~~~~~~~~~~~~
                %lu
1 warning generated.