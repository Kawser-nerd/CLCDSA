#include<stdio.h>

int main(){
	int a,b,ans=0;
	scanf("%d%d",&a,&b);
	ans=a-b;
	int ah=a/100;
	int at=(a-ah*100)/10;
	int ao=a%10;
	int bh=b/100;
	int bt=(b-bh*100)/10;
	int bo=b%10;
		if(9-ah>bh-1)ans+=(9-ah)*100;
		else if(9-ah<bh-1)ans+=(bh-1)*100;
		else {
			if(ah!=9&&bh!=1)ans+=(9-ah)*100;
			else {
				if(9-at>bt-0)ans+=(9-at)*10;
				else if(9-at<bt-0)ans+=(bt-0)*10;
				else{
					if(at!=9&&bt!=0)ans+=(9-at)*10;
					else{
				if(9-ao>bo-0)ans+=(9-ao);
				else if(9-ao<bo-0)ans+=(bo-0);
				else ans+=(9-ao);
					}
				}
			}
		}
	printf("%d\n",ans);
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&a,&b);
  ^