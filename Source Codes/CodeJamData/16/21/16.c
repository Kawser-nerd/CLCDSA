#include <stdio.h>
#include <string.h>

char letter(char c)
{
	return c - 'A';
}

void function()
{
	long i, j, n, number[10], alphabet[26];
	char string[2001];
	
	
	scanf("%s\n", string);	
	
	for(i = 0; i < 10; ++i)
		number[i] = 0;
	
	for(i = 0; i < 26; ++i)
		alphabet[i] = 0;
	
	n = strlen(string);
		
	for(i = 0; i < n; ++i)
		++alphabet[letter(string[i])];
	
	//ZERO
	n -= 4 * alphabet[letter('Z')];
	alphabet[letter('E')] -= alphabet[letter('Z')];
	alphabet[letter('R')] -= alphabet[letter('Z')];
	alphabet[letter('O')] -= alphabet[letter('Z')];
	number[0] += alphabet[letter('Z')];
	alphabet[letter('Z')] = 0;

	//TWO
	n -= 3 * alphabet[letter('W')];
	alphabet[letter('T')] -= alphabet[letter('W')];
	alphabet[letter('O')] -= alphabet[letter('W')];
	number[2] += alphabet[letter('W')];
	alphabet[letter('W')] = 0;

	//SIX
	n -= 3 * alphabet[letter('X')];
	alphabet[letter('S')] -= alphabet[letter('X')];
	alphabet[letter('I')] -= alphabet[letter('X')];
	number[6] += alphabet[letter('X')];
	alphabet[letter('X')] = 0;
	
	//SEVEN
	n -= 5 * alphabet[letter('S')];
	alphabet[letter('V')] -= alphabet[letter('S')];
	alphabet[letter('E')] -= 2 * alphabet[letter('S')];
	alphabet[letter('N')] -= alphabet[letter('S')];
	number[7] += alphabet[letter('S')];
	alphabet[letter('S')] = 0;
	
	//FIVE
	n -= 4 * alphabet[letter('V')];
	alphabet[letter('F')] -= alphabet[letter('V')];
	alphabet[letter('I')] -= alphabet[letter('V')];
	alphabet[letter('E')] -= alphabet[letter('V')];
	number[5] += alphabet[letter('V')];
	alphabet[letter('V')] = 0;
	
	//FOUR
	n -= 4 * alphabet[letter('U')];
	alphabet[letter('F')] -= alphabet[letter('U')];
	alphabet[letter('O')] -= alphabet[letter('U')];
	alphabet[letter('R')] -= alphabet[letter('U')];
	number[4] += alphabet[letter('U')];
	alphabet[letter('U')] = 0;
	
	//ONE
	n -= 3 * alphabet[letter('O')];
	alphabet[letter('N')] -= alphabet[letter('O')];
	alphabet[letter('E')] -= alphabet[letter('O')];
	number[1] += alphabet[letter('O')];
	alphabet[letter('O')] = 0;
	
	//THREE
	n -= 5 * alphabet[letter('R')];
	alphabet[letter('T')] -= alphabet[letter('R')];
	alphabet[letter('H')] -= alphabet[letter('R')];
	alphabet[letter('E')] -= 2 * alphabet[letter('R')];
	number[3] += alphabet[letter('R')];
	alphabet[letter('R')] = 0;
	
	//EIGHT
	n -= 5 * alphabet[letter('G')];
	alphabet[letter('E')] -= alphabet[letter('G')];
	alphabet[letter('I')] -= alphabet[letter('G')];
	alphabet[letter('H')] -= alphabet[letter('G')];
	alphabet[letter('T')] -= alphabet[letter('G')];
	number[8] += alphabet[letter('G')];
	alphabet[letter('G')] = 0;
	
	//NINE
	n -= 4 * alphabet[letter('I')];
	alphabet[letter('N')] -= 2 * alphabet[letter('I')];
	alphabet[letter('E')] -= alphabet[letter('I')];
	number[9] += alphabet[letter('I')];
	alphabet[letter('I')] = 0;
	
	
	for(i = 0; i < 10; ++i)
		for(j = 0; j < number[i]; ++j)
			printf("%ld", i);
}

int main()
{
	long i, j, k, count;
	
	
	scanf("%ld", &count);

	for(i = 1; i <= count; ++i)
	{
		printf("Case #%ld: ", i);
		function();
		printf("\n");	
	}
	
	
	return 0;
}
