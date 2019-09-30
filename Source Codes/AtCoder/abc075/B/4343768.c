#include <stdio.h>
int main()
{
	int h, w, i, j;
	scanf("%d%d", &h, &w);
	char s[h][w];
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			scanf("%c", &s[i][j]);
			if(s[i][j]=='.')s[i][j]='0';
			if(s[i][j]=='\n')j--;
		}
	}
	for(i=0;i<h;i++)
		for(j=0;j<w;j++)
			if(s[i][j]=='#')
				for(int k=-1;k<2;k++)
					for(int l=-1;l<2;l++){
						if(i+k<0 || i+k>=h || j+l<0 || j+l>=w || s[i+k][j+l]=='#')continue;
						s[i+k][j+l]++;
					}
	for(i=0;i<h;i++){
		for(j=0;j<w;j++)printf("%c", s[i][j]);
		putchar('\n');
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &h, &w);
  ^
./Main.c:9:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%c", &s[i][j]);
    ^