#include <stdio.h>
#include <string.h>

int ncase = -1;

#define change(x,y) case x: *p = y; break;

static char map[256];

void init()
{
	const char str[] = "ejp mysljylc kd kxveddknmc re jsicpdrysi\
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd\
de kr kd eoya kw aej tysr re ujdr lkgc jv";
	const char str2[] = "our language is impossible to understand\
there are twenty six factorial possibilities\
so it is okay if you want to just give up";

	size_t l;
	for(l = 0; l < strlen(str); l++)
		map[str[l]] = str2[l];
}

void solve(int icase)
{
	printf("Case #%d: ", icase + 1);

	char str[200];
	gets(str);
	char* p = str;
	while(*p)
	{
		*p = map[*p];
		*p++;
	}
	map['q'] = 'z';
	map['z'] = 'q';
	printf("%s\n", str);
}

int main()
{
	scanf("%d", &ncase);
	while(getchar()!='\n');
	
	init();
	int icase;
	for(icase = 0; icase < ncase; icase++)
		solve(icase);
}