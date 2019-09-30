#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
//1  2 1 3 2 4 2 5 8 7 a
//10 8 0 5 0 4 0 3 5 0 ans
//1  2 0 3 0 4 0 5 8 0 s

//1  1  2  2  2  3  4  5  7  8 so
//10 10 18 18 18 23 27 30 34 35wa
int main(void) {
	long long int i,j, N,b,max=0,gen=0;
	vector<long long int>a;//????
	vector<long long int>s;//???????????
	vector<long long int>so;//?????
	vector<long long int>wa;
	scanf("%lld", &N);
	for (i = 0; i <N; i++) {
		scanf("%lld", &b);
		a.push_back(b);
		so.push_back(b);
		if (max < b) { s.push_back(b); max = b; }else{ s.push_back(0); }
	}
	sort(so.begin(), so.end());
	wa.push_back(N*so[0]);
	for (i = 1; i < N; i++) {
		wa.push_back((so[i] - so[i - 1])*(N - i)+wa[i-1]);
	}
	max = 0; j = 0;
	for (i = 0; i < N; i++) {
		if (s[i] == 0) { printf("0\n"); continue; }
		while (-1) {
			if (s[i] <= so[j]) { break; }
			j++;
		}
		printf("%lld\n", wa[j] - max);
		max = wa[j];
	}

	return 0;
}