#include <stdio.h>
#include <string.h>


int main(void)
{
	char a[101],b[101];
	scanf("%s%s",a,b);
	int lena,lenb,len;
	lena=strlen(a);
	lenb=strlen(b);
	if(lena>lenb){printf("GREATER");}
	else if(lena<lenb){printf("LESS");}
		
	fprintf(stderr,"A=%s\nB=%s\n",a,b);	/* case:lena=lenb */
	int i;
	if(a != b && lena==lenb)
	{
	for(i=0;i<=lena-1;i++)
		{
		if(a[i]>b[i]){printf("GREATER"); break;}
		else if(a[i]<b[i]){printf("LESS"); break;}
		if(i==lena-1 && a[i]==b[i]){printf("EQUAL");}
		}
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s%s",a,b);
  ^