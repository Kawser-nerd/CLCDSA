#include<cstdio>
#include<set>
#include<cstring>
using namespace std;
const int MAXN = 500005;
int N;
char s[MAXN];
set <int> dec, pos[10];
void change(int x, char ch)
{
	pos[s[x] - '0'].erase(x);
	dec.erase(x);
	dec.erase(x - 1);
	s[x] = ch;
	pos[s[x] - '0'].insert(x);
	if (x < N - 1 && s[x] > s[x + 1])
		dec.insert(x);
	if (x && s[x - 1] > s[x])
		dec.insert(x - 1);
}
int main()
{
	scanf("%s", s);
	N = strlen(s);
	for (int i = 0; i < N; i++)
		pos[s[i] - '0'].insert(i);
	for (int i = 0; i < N - 1; i++)
		if (s[i] > s[i + 1])
			dec.insert(i);
	int sol = 1, last = -1;
	while (!dec.empty())
	{
		int curr = *dec.begin(), prev = *pos[s[curr] - '0'].begin(), it = N - 1;
		for (; it > curr && s[it] == '9'; it--)
			change(it, '0');
		change(it, s[it] + 1);
		for (int i = prev; i > last; i--)
			change(i, '0');
		last = prev;
		sol++;
	}
	printf("%d",sol);
}