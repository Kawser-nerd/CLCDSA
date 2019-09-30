#include <stdio.h>

/*
 * this values were calculated using a software called Pari
 * available at: http://www.ufr-mi.u-bordeaux.fr/~belabas/pari
 */

int resp[32]={1,5,27,143,751,935,607,903,991,335,47,943,471,55,447,463,991,95,607,263,151,855,527,743,351,135,407,903,791,135,647};

int main()
{
	int cnt, ncases;
	int n;
	scanf("%d",&ncases);
	for(cnt=1;cnt<=ncases;++cnt)
	{
		scanf("%d",&n);
		printf("Case #%d: %03d\n",cnt,resp[n]);
	}
	return 0;
}
