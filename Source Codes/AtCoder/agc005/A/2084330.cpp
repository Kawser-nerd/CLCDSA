#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include <string> 
#include <cmath>  
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <functional>

char x[200005];

int main(void) {
	char input;
	int i = 0;
	while (1) {
		scanf("%c", &input);
		if (input == '\n') {
			x[i] = '\0';
			break;
		}
		x[i] = input;
		if (input == 'T') {
			if (i > 0 && x[i - 1] == 'S') {
				i -= 2;
			}
		}
		i++;
	}
	printf("%d\n", strlen(x));
	return 0;
} ./Main.cpp:36:17: warning: format specifies type 'int' but the argument has type 'size_t' (aka 'unsigned long') [-Wformat]
        printf("%d\n", strlen(x));
                ~~     ^~~~~~~~~
                %zu
1 warning generated.