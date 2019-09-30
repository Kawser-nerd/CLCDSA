#include <stdio.h>
#include <string.h>

int main()
{
	int t, n, i, j;
	char a[26] = {"yhesocvxduiglbkrztnwjpfmaq"};
	char s[110];

	scanf("%d%*c", &t);

	for (i = 0; i < t; i++) {
		fgets(s, 105, stdin);
		
		n = strlen(s);

		s[n - 1] = '\0';
		n--;

		for (j = 0; j < n; j++) {
			if (s[j] == ' ') continue;

			s[j] = a[s[j] - 'a'];
		}

		printf("Case #%d: %s\n", i + 1, s);
	}

	return 0;
}