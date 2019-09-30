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
	int H = 0, W = 0;
	scanf("%d%d",&W,&H);
	printf("%s\n", (H / (W / 4)) != 3 ? "16:9" : "4:3");

	return 0;
}