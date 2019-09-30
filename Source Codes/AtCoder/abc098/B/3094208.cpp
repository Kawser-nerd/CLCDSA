#include <iostream>
#include <string>
using namespace std;
int main() {
	string S;
	int N;
	int max = 0;

	cin >> N >> S;

	for (int n = 1;n < N;n++) {
		int t1[26] = {0};
		int t2[26] = { 0 };
		int cnt = 0;
		for (int i = 0; i <= n; i++)
		{
			t1[S[i] - 'a']++;
		}
		for (int i = n+1; i < N; i++)
		{
			t2[S[i] - 'a']++;
		}
		for (int i = 0; i < 26; i++)
		{
			if (t1[i] != 0 && t2[i] != 0)
				cnt++;
		}
		if (max < cnt)
			max = cnt;
	}

	cout << max << endl;

	return 0;
}