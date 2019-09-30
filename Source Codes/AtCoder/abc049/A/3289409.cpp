#include <stdio.h>
#include <stdlib.h>
int main()
{
	char c;
	c = getchar();
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
		printf("vowel\n");
	else 
		printf("consonant\n");
	system("pause");
}