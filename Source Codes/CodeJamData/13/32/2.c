#include <stdio.h>

/* small only */

int main(void) {
	int caseNum,caseCount;
	scanf("%d",&caseNum);
	for(caseCount=1;caseCount<=caseNum;caseCount++) {
		const char* xmove[2]={"WE","EW"};
		const char* ymove[2]={"SN","NS"};
		int X,Y;
		int i;
		int rivFlag;
		scanf("%d%d",&X,&Y);
		printf("Case #%d: ",caseCount);
		if(X<0){rivFlag=1;X=-X;} else rivFlag=0;
		for(i=0;i<X;i++)fputs(xmove[rivFlag],stdout);
		if(Y<0){rivFlag=1;Y=-Y;} else rivFlag=0;
		for(i=0;i<Y;i++)fputs(ymove[rivFlag],stdout);
		putchar('\n');
	}
	return 0;
}
