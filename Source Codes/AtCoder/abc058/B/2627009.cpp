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
	char c = '\0';
	ll i = 0;

	while ((c = getchar()) != '\n') {
		str[i] = c;
		i += 2;
	}

	i = 1;
	while ((c = getchar()) != '\n') {
		str[i] = c;
		i += 2;
	}

	printf("%s", str);

	return 0;
}