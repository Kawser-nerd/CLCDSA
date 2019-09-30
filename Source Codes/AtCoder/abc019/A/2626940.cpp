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

	ll A = 0, B = 0, C = 0;
	
	scanf("%lld%lld%lld", &A, &B, &C);

	if (A <= B && B <= C || C <= B && B <= A)
		printf("%lld\n", B);
	else if (B <= A && A <= C || C <= A && A <= B)
		printf("%lld\n", A);
	else
		printf("%lld\n", C);
	return 0;
} ./Main.cpp:21:13: warning: '&&' within '||' [-Wlogical-op-parentheses]
        if (A <= B && B <= C || C <= B && B <= A)
            ~~~~~~~^~~~~~~~~ ~~
./Main.cpp:21:13: note: place parentheses around the '&&' expression to silence this warning
        if (A <= B && B <= C || C <= B && B <= A)
                   ^
            (               )
./Main.cpp:21:33: warning: '&&' within '||' [-Wlogical-op-parentheses]
        if (A <= B && B <= C || C <= B && B <= A)
                             ~~ ~~~~~~~^~~~~~~~~
./Main.cpp:21:33: note: place parentheses around the '&&' expression to silence this warning
        if (A <= B && B <= C || C <= B && B <= A)
                                       ^
                                (               )
./Main.cpp:23:18: warning: '&&' within '||' [-Wlogical-op-parentheses]
        else if (B <= A && A <= C || C <= A && A <= B)
                 ~~~~~~~^~~~~~~~~ ~~
./Main.cpp:23:18: note: place parentheses around the '&&' expression to silence this warning
        else if (...