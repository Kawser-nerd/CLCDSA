#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define DEBUGF(s, ...) fprintf(stderr, "DEBUG #%d: " s, t+1, ##__VA_ARGS__)

struct count {
	int n_p, n_r, n_s;
};

struct answer {
	char x1[8192];
	char x2[8192];
	char x3[8192];
	struct count c1;
	struct count c2;
	struct count c3;
};

struct answer answers[13];

void build_answers(void)
{
	int i;

	strcpy(answers[0].x1, "P");
	strcpy(answers[0].x2, "R");
	strcpy(answers[0].x3, "S");
	answers[0].c1.n_p = 1;
	answers[0].c2.n_r = 1;
	answers[0].c3.n_s = 1;
	
	for (i = 1; i <= 12; i++)
	{
		strcpy(answers[i].x1, answers[i-1].x1);
		strcat(answers[i].x1, answers[i-1].x2);
		answers[i].c1.n_p = answers[i-1].c1.n_p + answers[i-1].c2.n_p;
		answers[i].c1.n_r = answers[i-1].c1.n_r + answers[i-1].c2.n_r;
		answers[i].c1.n_s = answers[i-1].c1.n_s + answers[i-1].c2.n_s;

		strcpy(answers[i].x2, answers[i-1].x1);
		strcat(answers[i].x2, answers[i-1].x3);
		answers[i].c2.n_p = answers[i-1].c1.n_p + answers[i-1].c3.n_p;
		answers[i].c2.n_r = answers[i-1].c1.n_r + answers[i-1].c3.n_r;
		answers[i].c2.n_s = answers[i-1].c1.n_s + answers[i-1].c3.n_s;

		strcpy(answers[i].x3, answers[i-1].x2);
		strcat(answers[i].x3, answers[i-1].x3);
		answers[i].c3.n_p = answers[i-1].c2.n_p + answers[i-1].c3.n_p;
		answers[i].c3.n_r = answers[i-1].c2.n_r + answers[i-1].c3.n_r;
		answers[i].c3.n_s = answers[i-1].c2.n_s + answers[i-1].c3.n_s;
	}
}	

void do_test(int t)
{
	int n, r, p, s;

	scanf("%d %d %d %d", &n, &r, &p, &s);

	printf("Case #%d: ", t + 1);

	if (answers[n].c1.n_p == p && answers[n].c1.n_r == r && answers[n].c1.n_s == s)
		printf("%s\n", answers[n].x1);
	else if (answers[n].c2.n_p == p && answers[n].c2.n_r == r && answers[n].c2.n_s == s)
		printf("%s\n", answers[n].x2);
	else if (answers[n].c3.n_p == p && answers[n].c3.n_r == r && answers[n].c3.n_s == s)
		printf("%s\n", answers[n].x3);
	else
		printf("IMPOSSIBLE\n");
}

int main()
{
	int t, i;

	build_answers();

	scanf("%d", &t);
	
	for (i = 0; i < t; i++)
		do_test(i);

	return 0;
}
