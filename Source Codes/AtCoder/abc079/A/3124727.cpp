#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	cin >> s;

	if (((s[0] == s[1]) && (s[2] == s[1]) || (s[1] == s[2]) && (s[3] == s[2])))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
} ./Main.cpp:8:22: warning: '&&' within '||' [-Wlogical-op-parentheses]
        if (((s[0] == s[1]) && (s[2] == s[1]) || (s[1] == s[2]) && (s[3] == s[2])))
             ~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~ ~~
./Main.cpp:8:22: note: place parentheses around the '&&' expression to silence this warning
        if (((s[0] == s[1]) && (s[2] == s[1]) || (s[1] == s[2]) && (s[3] == s[2])))
                            ^
             (                               )
./Main.cpp:8:58: warning: '&&' within '||' [-Wlogical-op-parentheses]
        if (((s[0] == s[1]) && (s[2] == s[1]) || (s[1] == s[2]) && (s[3] == s[2])))
                                              ~~ ~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~
./Main.cpp:8:58: note: place parentheses around the '&&' expression to silence this warning
        if (((s[0] == s[1]) && (s[2] == s[1]) || (s[1] == s[2]) && (s[3] == s[2])))
                                                                ^
                                                 (                               )
2 warni...