#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;


int main(void)
{
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		int p, k, l;
		scanf("%d%d%d", &p, &k, &l);
		int freq[1024];
		for (int i = 0; i < l; i++)
			scanf("%d", &freq[i]);
		sort(freq, freq + l);
		long long all = 0;
		long long cnum = 1;
		long long crem = k;
		for (int i = l-1; i >= 0; i--) {
			long long x = freq[i];
			all += x * cnum;
			crem--;
			if (!crem) {
				cnum++;
				crem = k;
			}
		}
		cout << "Case #" << tc << ": " << all << endl;
	}
	return 0;
}
