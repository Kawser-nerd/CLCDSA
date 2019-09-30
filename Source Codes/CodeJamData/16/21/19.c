#include<stdio.h>

#define SIZE 2002

int Case;
char S[SIZE];
int f1[26], f2[10];

void readCase()
{
	scanf("%s", S);
}

void solveCase()
{
	int i;
	for (i=0; i<26; i++)
		f1[i] = 0;
	for (i=0; i<10; i++)
		f2[i] = 0;
	for (i=0; S[i]; i++)
		f1[S[i]-'A']++;
	// ZERO
	f2[0] = f1['Z'-'A'];
	f1['E'-'A'] -= f2[0];
	f1['R'-'A'] -= f2[0];
	f1['O'-'A'] -= f2[0];
	// TWO
	f2[2] = f1['W'-'A'];
	f1['T'-'A'] -= f2[2];
	f1['O'-'A'] -= f2[2];
	// SIX
	f2[6] = f1['X'-'A'];
	f1['S'-'A'] -= f2[6];
	f1['I'-'A'] -= f2[6];
	// EIGHT
	f2[8] = f1['G'-'A'];
	f1['E'-'A'] -= f2[8];
	f1['I'-'A'] -= f2[8];
	f1['H'-'A'] -= f2[8];
	f1['T'-'A'] -= f2[8];
	// THREE
	f2[3] = f1['T'-'A'];
	f1['H'-'A'] -= f2[3];
	f1['R'-'A'] -= f2[3];
	f1['E'-'A'] -= f2[3];
	f1['E'-'A'] -= f2[3];
	// FOUR
	f2[4] = f1['U'-'A'];
	f1['F'-'A'] -= f2[4];
	f1['O'-'A'] -= f2[4];
	f1['R'-'A'] -= f2[4];
	// ONE
	f2[1] = f1['O'-'A'];
	f1['N'-'A'] -= f2[1];
	f1['E'-'A'] -= f2[1];
	// SEVEN
	f2[7] = f1['S'-'A'];
	f1['E'-'A'] -= f2[7];
	f1['V'-'A'] -= f2[7];
	f1['E'-'A'] -= f2[7];
	f1['N'-'A'] -= f2[7];
	// FIVE
	f2[5] = f1['V'-'A'];
	// NINE
	f2[9] = f1['N'-'A']/2;
}

void printCase()
{
	int i;
	printf("Case #%d: ", Case);
	for (i=0; i<10; i++) while (f2[i]) {
		printf("%d", i);
		f2[i]--;
	}
	printf("\n");
}

int main()
{
	int T;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for (Case=1; Case<=T; Case++) {
		readCase();
		solveCase();
		printCase();
	}
	return 0;
}
