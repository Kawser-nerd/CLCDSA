#include<stdio.h>

int main() {
	int N,cs=0;
	int x,y;
	for(scanf("%d",&N);N--;) {
		scanf("%d %d",&x,&y);
		printf("Case #%d: ",++cs);
		for(;x>0;x--) printf("WE");
		for(;x<0;x++) printf("EW");
		for(;y>0;y--) printf("SN");
		for(;y<0;y++) printf("NS");
		puts("");
	}
	return 0;
}
