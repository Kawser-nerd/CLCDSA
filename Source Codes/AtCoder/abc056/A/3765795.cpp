#include <iostream>
using namespace std;

int main() {
	char a, b;

	cin >> a >> b;

	if (a == 'H' && b == 'H' || a == 'D' && b == 'D') cout << "H" << endl;
	else cout << "D" << endl;
} ./Main.cpp:9:15: warning: '&&' within '||' [-Wlogical-op-parentheses]
        if (a == 'H' && b == 'H' || a == 'D' && b == 'D') cout << "H" << endl;
            ~~~~~~~~~^~~~~~~~~~~ ~~
./Main.cpp:9:15: note: place parentheses around the '&&' expression to silence this warning
        if (a == 'H' && b == 'H' || a == 'D' && b == 'D') cout << "H" << endl;
                     ^
            (                   )
./Main.cpp:9:39: warning: '&&' within '||' [-Wlogical-op-parentheses]
        if (a == 'H' && b == 'H' || a == 'D' && b == 'D') cout << "H" << endl;
                                 ~~ ~~~~~~~~~^~~~~~~~~~~
./Main.cpp:9:39: note: place parentheses around the '&&' expression to silence this warning
        if (a == 'H' && b == 'H' || a == 'D' && b == 'D') cout << "H" << endl;
                                             ^
                                    (                   )
2 warnings generated.