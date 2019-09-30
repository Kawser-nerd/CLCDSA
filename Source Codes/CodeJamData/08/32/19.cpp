#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int maxL = 40 + 5;


int num[maxL], op[maxL];
char s[maxL];
int L, ans, data;

void getinf()
{
  gets(s);
  L = strlen(s);
  for (int i = 0; i < L; i++) num[i] = s[i] - '0';
}

bool ugly(long long x)
{
  return (!(x % 2) || !(x % 3) || !(x % 5) || !(x % 7));
}

void solve()
{
  int p = 1, x;
  long long last, now, sign;
  ans = 0;
  for (int i = 1; i <= L - 1; i++) p *= 3;
  for (int i = 0; i < p; i++)
    {
      x = i;
      for (int k = 0; k < L - 1; k++) op[k] = x % 3, x /= 3;
      last = 0;
      now = num[0];
      sign = 1;
      for (int k = 0; k < L - 1; k++)
	{
	  if (!op[k])
	    {
	      now = now * 10 + num[k + 1];
	    }
	  else 
	    {
	      last += sign * now;
	      now = num[k + 1];
	      if (op[k] == 2) sign = -1; else sign = 1;
	    }
	}
      last += sign * now;
      if (ugly(last)) ans++;
    }
}

int main()
{
  scanf("%d\n", &data);
  for (int tot = 1; tot <= data; tot++)
    {
      getinf();
      solve();
      cout << "Case #" << tot << ": " << ans << endl; 
    }
}
