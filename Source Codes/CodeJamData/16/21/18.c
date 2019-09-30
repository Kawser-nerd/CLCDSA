/*Getting the Digits*/

#include<stdio.h>
#include<string.h>

char S[2005];
int digits[10], counts[26];

void count_zeros(void);
void count_ones(void);
void count_twos(void);
void count_threes(void);
void count_fours(void);
void count_fives(void);
void count_sixes(void);
void count_sevens(void);
void count_eights(void);
void count_nines(void);

int main()
{
	int i, length, t, T;
	freopen("A-large.in", "r", stdin);
	freopen("A.out", "w", stdout);
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		scanf("%s", S);
		length = strlen(S);
		memset(counts, 0, sizeof(counts));
		memset(digits, 0, sizeof(digits));
		for (i = 0; i < length; i++)
			counts[S[i] - 'A']++;
		count_zeros();
		count_twos();
		count_fours();
		count_ones();
		count_threes();
		count_fives();
		count_sixes();
		count_sevens();
		count_eights();
		count_nines();
		printf("Case #%d: ", t);
		for (i = 0; i <= 9; i++)
		{
			while (digits[i])
			{
				printf("%d", i);
				digits[i]--;
			}
		}
		printf("\n");
	}
	return 0;
}

void count_zeros(void)
{
	while (counts['Z' - 'A'])
	{
		digits[0]++;
		counts['Z' - 'A']--;
		counts['E' - 'A']--;
		counts['R' - 'A']--;
		counts['O' - 'A']--;
	}
}

void count_ones(void)
{
	while (counts['O' - 'A'])
	{
		digits[1]++;
		counts['O' - 'A']--;
		counts['N' - 'A']--;
		counts['E' - 'A']--;
	}
}

void count_twos(void)
{
	while (counts['W' - 'A'])
	{
		digits[2]++;
		counts['T' - 'A']--;
		counts['W' - 'A']--;
		counts['O' - 'A']--;
	}
}

void count_threes(void)
{
	while (counts['R' - 'A'])
	{
		digits[3]++;
		counts['T' - 'A']--;
		counts['H' - 'A']--;
		counts['R' - 'A']--;
		counts['E' - 'A']--;
		counts['E' - 'A']--;
	}
}

void count_fours(void)
{
	while (counts['U' - 'A'])
	{
		digits[4]++;
		counts['F' - 'A']--;
		counts['O' - 'A']--;
		counts['U' - 'A']--;
		counts['R' - 'A']--;
	}
}

void count_fives(void)
{
	while (counts['F' - 'A'])
	{
		digits[5]++;
		counts['F' - 'A']--;
		counts['I' - 'A']--;
		counts['V' - 'A']--;
		counts['E' - 'A']--;
	}
}

void count_sixes(void)
{
	while (counts['X' - 'A'])
	{
		digits[6]++;
		counts['S' - 'A']--;
		counts['I' - 'A']--;
		counts['X' - 'A']--;
	}
}

void count_sevens(void)
{
	while (counts['V' - 'A'])
	{
		digits[7]++;
		counts['S' - 'A']--;
		counts['E' - 'A']--;
		counts['V' - 'A']--;
		counts['E' - 'A']--;
		counts['N' - 'A']--;
	}
}

void count_eights(void)
{
	while (counts['G' - 'A'])
	{
		digits[8]++;
		counts['E' - 'A']--;
		counts['I' - 'A']--;
		counts['G' - 'A']--;
		counts['H' - 'A']--;
		counts['T' - 'A']--;
	}
}

void count_nines(void)
{
	while (counts['N' - 'A'])
	{
		digits[9]++;
		counts['N' - 'A']--;
		counts['I' - 'A']--;
		counts['N' - 'A']--;
		counts['E' - 'A']--;
	}
}