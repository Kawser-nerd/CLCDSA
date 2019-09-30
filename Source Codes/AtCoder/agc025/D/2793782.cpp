#include <cstdio>

using namespace std;

int n, d1, d2, n1, n2;

int main(){
	scanf("%d%d%d", &n, &d1, &d2);
	n1 = n2 = 0;
	
	while (d1 % (1 << (n1 + 1)) == 0) n1++;
	while (d2 % (1 << (n2 + 1)) == 0) n2++;
	int c = 0;
	
	for (int i = 0; i < 2 * n && c < n * n; i++){
		for (int j = 0; j < 2 * n && c < n * n; j++){
			if ((n1 % 2 == 0 ? (i >> (n1 / 2)) % 2 == (j >> (n1 / 2)) % 2:(i >> (n1 / 2)) % 2 == 0)
	 		  &&(n2 % 2 == 0 ? (i >> (n2 / 2)) % 2 == (j >> (n2 / 2)) % 2:(i >> (n2 / 2)) % 2 == 0)){
					printf("%d %d\n", i, j); c++;
				}
		}
	}
	
	return 0;
}