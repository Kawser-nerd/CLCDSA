#include<algorithm>
#include<iostream>
#include<math.h>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<string>
#include<vector>

using namespace std;
int main(void) {
	char s[5] = "\0";
	scanf("%s", s);
	printf("%s\n", (s[0] == s[1] && s[2] == s[3] && s[0] == s[2]) ? "SAME" : "DIFFERENT");

	return 0;
}