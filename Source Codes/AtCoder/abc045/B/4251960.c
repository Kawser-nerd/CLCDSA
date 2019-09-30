#include <stdio.h>
#include <string.h>

int main(void)
{
	char sa[100],sb[100],sc[100];
	int ca[1]={0},cb[1]={0},cc[1]={0};
	scanf("%s%s%s",sa,sb,sc);
	int lena,lenb,lenc;
	lena=strlen(sa);
	lenb=strlen(sb);
	lenc=strlen(sc);

	char win='z';
	char turn='a';
	while(win=='z'){
		switch(turn)
		{
		case 'a':
			if(ca[0]==lena)
				{win='A';}

			turn=sa[ca[0]];
			ca[0]++;
			break;
		case 'b':
			if(cb[0]==lenb)
				{win='B';}
			turn=sb[cb[0]];
			cb[0]++;
			break;
		case 'c':
			if(cc[0]==lenc)
				{win='C';}
			turn=sc[cc[0]];
			cc[0]++;
			break;
		}
		}
	printf("%c\n",win);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s%s%s",sa,sb,sc);
  ^