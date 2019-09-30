#include <stdio.h>

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);

	int Test;

	scanf ("%d",&Test); for (int Case=1;Case<=Test;Case++){
		int r,chk[17]={0};
		for (int k=0;k<2;k++){
			scanf ("%d",&r);
			for (int i=1;i<=4;i++){
				for (int j=1;j<=4;j++){
					int x;
					scanf ("%d",&x);
					if (i == r) chk[x]++;
				}
			}
		}

		int res,cnt=0;
		for (int i=1;i<=16;i++) if (chk[i] == 2){
			res = i; cnt++;
		}

		printf ("Case #%d: ",Case);
		if (cnt == 0) puts("Volunteer cheated!");
		else if (cnt == 1) printf ("%d\n",res);
		else puts("Bad magician!");
	}

	return 0;
}