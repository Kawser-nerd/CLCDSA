#include <iostream>
using namespace std;

char a[100], b[100];

int main() {
	int st;
	scanf("%d", &st);
	gets(a);
	for(int t=0;t<st;++t) {
		cout << "Case #" << t + 1 << ": ";
		memset( a, 0, sizeof(a));
		gets(a);
		int len = strlen(a);
		if(next_permutation( a, a + len)) {
			cout << a << endl;
		}
		else {
			a[len] = '0';
			++len;
			sort( a, a + len);
			for(int i=0;i<len;++i) if(a[i] != '0') {
				a[0] = a[i];
				a[i] = '0';
				cout << a << endl;
				break;
			}
		}
	}
	return 0;
}
