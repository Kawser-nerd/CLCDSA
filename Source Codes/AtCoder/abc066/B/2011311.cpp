#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
	char moji[200],*p;
	int len,i;
	p = moji;
	cin >> moji;
	len = strlen(moji);
	p[len-1] = '\0';

	while (1) {
		len = strlen(moji);
		if (len % 2 == 0) {
			for (i = 0; i < len / 2; i++) {
				if (p[i] != p[i + len / 2])
					break;
			}
			if (i == len / 2) {
				cout << len;
				break;
			}
		}
		p[len-1] = '\0';
	}

	return 0;
}