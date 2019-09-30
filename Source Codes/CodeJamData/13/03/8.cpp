#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include <string>
#include <ctime>

using namespace std;

#define rep(x, y, z) for(int x = (y), end##x = (z); x < end##x; x++)
#define all(x) (x).begin(),(x).end()

#ifdef LOCAL_DEBUG

#define DebugPrint(...) fprintf(stderr, __VA_ARGS__);

#else

#define DebugPrint(...)

#endif

typedef long long ll;
typedef pair<int, int> pii;


const int BASELEN = 9;
const int BASE = 1000000000;

ll tenPow[15];

int numLen(ll val)
{
	int rv = 0;
	rep(i, 0, 15)
	{
		if (tenPow[i] > val)
		{
			rv = i;
			break;
		}
	}
	return rv;
}

const int BUFLEN = 14;

struct LA
{
	int len;
	int totLen;
	ll buf[BUFLEN];

	void setInd(int i, int val)
	{
		int bufInd = i / BASELEN;
		int indInBuf = i % BASELEN;
		buf[bufInd] -= buf[bufInd] / tenPow[indInBuf] % 10 * tenPow[indInBuf];
		buf[bufInd] += val * tenPow[indInBuf];
	}

	int getCif(int i)
	{
		int bufInd = i / BASELEN;
		int indInBuf = i % BASELEN;
		return buf[bufInd] / tenPow[indInBuf] % 10;
	}

	void setTotLen(int newLen)
	{
		totLen = newLen;
		len = (newLen + BASELEN - 1) / BASELEN;
	}

	bool checkPalindrome()
	{
		bool bad = 0;
		rep(i, 0, totLen/2)
		{
			int cif1 = getCif(i);
			int cif2 = getCif(totLen - i - 1);
			if (cif1 != cif2)
			{
				bad = 1;
				break;
			}
		}
		return !bad;
	}

	void print(char *printBuf)
	{
		int printedCount = 0;
		sprintf(printBuf + printedCount, "%lld%n", buf[len - 1], &printedCount);
		rep(i, 1, len)
		{
			int cp = 0;
			sprintf(printBuf + printedCount, "%.9lld%n", buf[len - i - 1], &cp);
			printedCount += cp;
		}
	}
} la1, la2;

void makeMul()
{
	memset(la2.buf, 0, sizeof(la2.buf));

	rep(i, 0, la1.len)
	{
		rep(j, 0, la1.len)
		{
			ll res = la1.buf[i] * la1.buf[j];
			la2.buf[i+j] += res % tenPow[BASELEN];
			la2.buf[i+j+1] += res / tenPow[BASELEN];
		}
	}

	ll tr = 0;

	int newLen = 0;
	rep(i, 0, la1.len + la1.len + 2)
	{
		la2.buf[i] += tr;
		tr = la2.buf[i] / tenPow[BASELEN];
		la2.buf[i] %= tenPow[BASELEN];
		if (la2.buf[i] > 0)
			newLen = i+1;
	}
	la2.setTotLen((newLen-1) * BASELEN + numLen(la2.buf[newLen-1]));
}

void checkAndPrint()
{
	char buf[150];
	makeMul();
	if (la2.checkPalindrome())
	{
		la2.print(buf);
		int len = strlen(buf);
		printf("%.3d ", len);

		if (len == 1)
			printf("BIDA\n");

		la1.print(buf);
		printf("%s ", buf);
		//DebugPrint("%s ", buf);

		la2.print(buf);
		printf("%s\n", buf);
		//DebugPrint("%s\n", buf);
	}
}

void init()
{
	tenPow[0] = 1;
	rep(i, 1, 15)
	{
		tenPow[i] = tenPow[i-1] * 10;
	}
}

int main()
{
	//
#ifdef LOCAL_DEBUG

	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);

#else

	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);

#endif

	_set_printf_count_output(1);

	clock_t cl = clock();

	init();

	int maxMask = 0;

	char buf[150];

	for (int len = 2; len <= 25; len++)
	{
		DebugPrint("-------------%d-------------\n", len);
		maxMask = 1 << (len-1);
		maxMask--;

		int fullLen = 2 * len;
		la1.setTotLen(fullLen);

		la1.setInd(0, 1);
		la1.setInd(fullLen - 1, 1);

		rep(j, 0, maxMask + 1)
		{
			rep(k, 0, len - 1)
			{
				if (j & (1 << k))
				{
					la1.setInd(k+1, 1);
					la1.setInd(fullLen - 1 - 1 - k, 1);
				}
				else
				{
					la1.setInd(k+1, 0);
					la1.setInd(fullLen - 1 - 1 - k, 0);
				}
			}

			checkAndPrint();
		}

		rep(i, 0, fullLen)
			la1.setInd(i, 0);

		la1.setInd(0, 2);
		la1.setInd(fullLen - 1, 2);

		checkAndPrint();

		fullLen++;

		la1.setTotLen(fullLen);
		la1.setInd(0, 1);
		la1.setInd(fullLen - 1, 1);
		rep(j, 0, maxMask + 1)
		{
			rep(k, 0, len - 1)
			{
				if (j & (1 << k))
				{
					la1.setInd(k+1, 1);
					la1.setInd(fullLen - 1 - 1 - k, 1);
				}
				else
				{
					la1.setInd(k+1, 0);
					la1.setInd(fullLen - 1 - 1 - k, 0);
				}
			}

			rep(t, 0, 3)
			{
				la1.setInd(fullLen / 2, t);

				checkAndPrint();
			}
		}

		rep(i, 0, fullLen)
			la1.setInd(i, 0);

		la1.setInd(0, 2);
		la1.setInd(fullLen - 1, 2);
		checkAndPrint();

		la1.setInd(fullLen / 2, 1);
		checkAndPrint();
	}

#ifdef LOCAL_DEBUG

	fprintf(stderr, "\nTime used: %lf\n", (clock() - cl) / (double)CLOCKS_PER_SEC);

#endif

	return 0;
}