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
	int X = 0,ans = 1;
	scanf("%d", &X);
	while ((ans * ans++) <= X) {}
	printf("%d\n", (ans - 2) * (ans - 2));
	return 0;
} ./Main.cpp:15:19: warning: unsequenced modification and access to 'ans' [-Wunsequenced]
        while ((ans * ans++) <= X) {}
                ~~~      ^
1 warning generated.