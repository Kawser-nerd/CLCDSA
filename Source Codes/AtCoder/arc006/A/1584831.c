#include<stdio.h>

int main()
{
	int E[6], B, L[6], cnt = 0, i, j, bonus = 0;

	for(i = 0; i < 6; i++)
		scanf("%d", &E[i]);
	scanf("%d", &B);
	for(i = 0; i < 6; i++)
		scanf("%d", &L[i]);

	for(i = 0; i < 6; i++)
		for(j = 0; j < 6; j++)
			if(E[i] == L[j])
				cnt++;

	for(i = 0; i < 6; i++)
		if(B == L[i])
			bonus++;

	switch(cnt)
	{
		case 6: puts("1"); break;
		case 5: if(bonus)
				puts("2");
			else
				puts("3"); break;
		case 4: puts("4"); break;
		case 3: puts("5"); break;
		default: puts("0"); break;
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &E[i]);
   ^
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &B);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &L[i]);
   ^