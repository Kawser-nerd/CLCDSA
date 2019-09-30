#include<algorithm>
#include<iostream>
#include<math.h>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<string>
#include<vector>

#define ll long long
#define ull unsigned long long

using namespace std;
int main(void) {

	char str[101] = "\0";
	ll i = 0;
	scanf("%s", str);
	scanf("%d", &i);
	printf("%c\n", str[i - 1]);

	return 0;
} ./Main.cpp:20:14: warning: format specifies type 'int *' but the argument has type 'long long *' [-Wformat]
        scanf("%d", &i);
               ~~   ^~
               %lld
1 warning generated.