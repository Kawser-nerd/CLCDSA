#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DEBUG 0
#define NINF -1
#define PINF 1E9+7

#define MAX_INPUT 100000
#define ATOZ 26

int n,count[ATOZ]={},species=0;
char *s;

int main()
{
	int i,j;
	long ans=0,tmp;

	scanf("%d",&n);
	s = (char *)malloc(sizeof(char) * (n+1));
	scanf("%s",s);

	for (i=0;i<n;i++) {
		if (count[s[i]-'a']==0) species++;
		count[s[i]-'a']++;
		
		tmp = 1;
		for (j=0;j<ATOZ;j++) {
			if (count[j]==0) continue;
			if (j==s[i]-'a') continue;

			tmp *= count[j]+1;
			tmp = fmod(tmp,PINF);
		}
		if (DEBUG) printf("tmp = %ld\n",tmp);
		ans = fmod(ans + tmp , PINF);
	}


	printf("%ld\n",ans);
	free(s);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:22:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^