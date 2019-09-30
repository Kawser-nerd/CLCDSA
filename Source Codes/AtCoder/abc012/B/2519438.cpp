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
	int S = 0;
	scanf("%d", &S);
	
	printf("%02d:%02d:%02d\n", S / 3600, (S % 3600) / 60, S % 60);

	return 0;
}