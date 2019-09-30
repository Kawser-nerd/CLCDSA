#include <stdio.h>
int main()
{
	int T;scanf("%d",&T);
	for (int kase=1;kase<=T;++kase)
	{
		int R,C,W;
		scanf("%d %d %d",&R,&C,&W);
		int rr = 0;
		while (R>1)
		{
			rr += C/W;
			R--;
		}

		while (C>=2*W)
		{
			rr++;
			C-=W;
		}
		int cross = 2*W-C;
		if (W == C) 
			cross = W;
		else
			rr += (C-cross)/2 + 1;
		rr += cross;
		printf("Case #%d: %d\n",kase,rr);
	}
	return 0;
}