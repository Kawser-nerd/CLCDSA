#include <iostream>
using namespace std;
const int N = 3000;
bool sugar[N + 5], water[N + 5];
int main()
{
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	sugar[0] = water[0] = true;
	for (int i : {c, d})
		for (int j = i; j <= N; j++)
			sugar[j] |= sugar[j - i];
	for (int i : {a, b})
		for (int j = i; j <= N; j++)
			water[j] |= water[j - i];
	int s = 0, w = a;
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= N; j++)
			if (sugar[i] && water[j] && i + 100 * j <= f && e * j >= i && i * w > s * j)
			{
				s = i;
				w = j;
			}
	cout << s + 100 * w << ' ' << s << endl;
	return 0;
}