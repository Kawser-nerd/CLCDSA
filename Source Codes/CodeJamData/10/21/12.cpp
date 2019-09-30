#include <stdio.h>
#include <stdarg.h>
#include <cstring>
#include <string>
#include <map>


#define clr(a) memset(a, 0, sizeof(a))

#define DEBUG 1

void dbg(const char * fmt, ...)
{
#if DEBUG
	va_list args;
	va_start(args, fmt);
	vfprintf(stderr, fmt, args);
	va_end(args);
	fflush(stderr);
#endif
}

int ans= 0;
char in[1000000];
int pos;

bool has_next()
{
	return in[pos] != 0;
}

std::string next()
{
	std::string ans = "";
	do
	{
		ans += in[pos];
		pos++;
	}
	while(in[pos] != 0 && in[pos] != '/');
	return ans;
}


class dir
{
public:
	std::map<std::string, dir> subdirs;
	void parse()
	{
		if (!has_next())
			return;
		std::string cur = next();
		if (subdirs.find(cur) == subdirs.end())
		{
			subdirs.insert(std::make_pair(cur, dir()));
			ans++;
		}
		subdirs[cur].parse();
	}

} root;



void solve(int test_case)
{
	printf("Case #%d: ", test_case);
	root.subdirs.clear();
	int n,k;
	scanf("%d%d\n", &n, &k);
	for(int i = 0; i < n; i++)
	{
		gets(in);
		pos = 0;
		root.parse();
	}
	ans = 0;
	for(int i = 0; i < k; i++)
	{
		gets(in);
		pos = 0;
		root.parse();
	}
	printf("%d\n", ans);
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		solve(i);

	return 0;
}
