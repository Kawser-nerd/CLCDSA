#include <stdio.h>

char S[101];

int main()
{
	scanf ("%s",S+1);
	int a,b,c,d; scanf ("%d %d %d %d",&a,&b,&c,&d);
	if (a == 0) putchar('\"');
	for (int i=1;S[i];i++){
		putchar(S[i]);
		if (i == a || i == b || i == c || i == d) printf ("\"");
	}
	puts("");
	return 0;
}