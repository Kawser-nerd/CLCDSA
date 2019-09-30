#include <stdio.h>

int main(int argc, char **argv)
{
	unsigned int no_cases, case_no;
	scanf("%u", &no_cases);
	for (case_no = 0; case_no != no_cases; case_no++)
	{
		unsigned int r, y, b, s[3], e[3], fc, xc, yc, cc;
#define er e[0]
#define ey e[1]
#define eb e[2]
#define g s[0]
#define v s[1]
#define o s[2]
#define PLACE(c) {putchar("RYB"[c]); e[c]--; \
while (s[c]) {putchar("GVO"[c]); putchar("RYB"[c]); s[c]--;}}
		char can = 1;
		scanf("%*u%u%u%u%u%u%u", &r, &o, &y, &g, &b, &v);
		if (o > b || g > r || v > y || \
		    !!r + !!y + !!b > 1 && \
		     (o && o == b || g && g == r || v && v == y))
			{can = 0;}
		er = r - g;
		ey = y - v;
		eb = b - o;
		if (er > ey + eb || ey > eb + er || eb > er + ey)
			{can = 0;}
		
		printf("Case #%u: ", case_no + 1);
		if (!can)
		{
			puts("IMPOSSIBLE");
			continue;
		}
		
		if (!(er || ey || eb))
		{
			cc = r ? 0 : y ? 1 : b ? 2 : !fputs("!!0", stderr);
			while (s[cc])
			{
				putchar("GVO"[cc]);
				putchar("RYB"[cc]);
				s[cc]--;
			}
			putchar('\n');
			continue;
		}
		fc = er > ey && er > eb ? 0 : ey > eb ? 1 : 2;
		xc = (fc + 1) % 3;
		yc = (fc + 2) % 3;
		PLACE(fc)
		while (e[fc])
		{
			cc = e[xc] > e[yc] ? xc : yc;
			PLACE(cc)
			PLACE(fc)
		}
		if (e[xc] < e[yc])
		{
			cc = xc;
			xc = yc;
			yc = cc;
		}
		if (e[xc] > e[yc])
		{
			PLACE(xc)
		}
		while (e[yc])
		{
			PLACE(yc)
			PLACE(xc)
		}
		putchar('\n');
		if (e[0] || e[1] || e[2] || s[0] || s[1] || s[2])
		{
			fprintf(stderr, "Leftover unicorns -- case %u!", case_no);
		}
	}
	return 0;
}
