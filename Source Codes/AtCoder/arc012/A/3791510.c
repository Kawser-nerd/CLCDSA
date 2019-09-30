#include <stdio.h>

int main()
{
	char d[10];
	scanf("%s", d);
	if (d[0]=='M' && d[1]=='o'&&d[2]=='n'&&d[3]=='d'&&d[4]=='a'&&d[5]=='y') {
		printf("5\n");
	} else if (d[0]=='T'&&d[1]=='u'&&d[2]=='e'&&d[3]=='s'&&d[4]=='d'&&d[5]=='a'&&d[6]=='y') {
		printf("4\n");
	} else if (d[0]=='W'&&d[1]=='e'&&d[2]=='d'&&d[3]=='n'&&d[4]=='e'&&d[5]=='s'&&d[6]=='d'&&d[7]=='a'&&d[8]=='y') {
		printf("3\n");
	} else if (d[0]=='T'&&d[1]=='h'&&d[2]=='u'&&d[3]=='r'&&d[4]=='s'&&d[5]=='d'&&d[6]=='a'&&d[7]=='y') {
		printf("2\n");
	} else if (d[0]=='F'&&d[1]=='r'&&d[2]=='i'&&d[3]=='d'&&d[4]=='a'&&d[5]=='y') {
		printf("1\n");
	} else {
		printf("0\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", d);
  ^