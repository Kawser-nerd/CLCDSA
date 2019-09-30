#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int change[26];
	int T, i;
	char lettre;
	change[0] = 24;
	change[1] = 7;
	change[2] = 4;
	change[3] = 18;
	change[4] = 14;
	change[5] = 2;
	change[6] = 21;
	change[7] = 23;
	change[8] = 3;
	change[9] = 20;
	change[10] = 8;
	change[11] = 6;
	change[12] = 11;
	change[13] = 1;
	change[14] = 10;
	change[15] = 17;
	change[16] = 25;
	change[17] = 19;
	change[18] = 13;
	change[19] = 22;
	change[20] = 9;
	change[21] = 15;
	change[22] = 5;
	change[23] = 12;
	change[24] = 0;
	change[25] = 16;

	scanf("%d\n", &T);
	for(i = 0; i < T; i++)
	{
		printf("Case #%d: ", i+1);
		lettre = getchar();
		while(lettre != '\n' && lettre != EOF)
		{
			if(lettre == ' ') printf(" ");
			else printf("%c", change[lettre-97]+97);
			lettre = getchar();
		}
		printf("\n");
	}

	return 0;
}
