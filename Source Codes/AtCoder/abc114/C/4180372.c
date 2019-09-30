#include <stdio.h>

long int dfs(long int o, long int n);//0~n??????????

int main(void)
{
	long int n;
	scanf("%ld", &n);
	printf("%ld", dfs(0, n));
	return 0;
}

//0??????3,5,7,???????????????????????
long int dfs(long int o, long int n)
{
	if (o > n)return 0;//????
	long int t = o, flag3 = 0, flag5 = 0, flag7 = 0, count = 0;

	//???? o ?753????????
	while (t > 0) {
		if ((t % 10) == 3)flag3 = 1;
		else if ((t % 10) == 5)flag5 = 1;
		else if ((t % 10) == 7)flag7 = 1;
		if ((flag3 + flag5 + flag7) == 3) {
			count++;
			break;
		}
		t /= 10;
	}

	//3,5,7,????????????????????
	count += dfs(o*10 + 3, n);
	count += dfs(o*10 + 5, n);
	count += dfs(o*10 + 7, n);

	return count;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld", &n);
  ^