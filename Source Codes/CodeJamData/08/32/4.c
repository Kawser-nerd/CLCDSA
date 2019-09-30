#include<stdio.h>
#include<string.h>
#include<math.h>


int main()
{
	int t,tn;
	char str[15];
	__int64 l,n;
	__int64 re,x,y;
	__int64 i,j,k,index;	
	int yun;

	freopen("B-small-attempt0.in.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	scanf("%d",&t);
	for(tn=0; tn<t;tn++) {
		scanf("%s",&str);	
		l = strlen(str);
		if(l == 1) {
			x = str[0] - '0';
			if(x%2==0||x%3==0||x%5==0||x%7==0) printf("Case #%d: 1\n",tn+1);
			else printf("Case #%d: 0\n",tn+1);
			continue;
		}
		n = pow(3,(l-1));
		re = 0;
		for(i = 0; i < n;i++) {
			x = 0; y = str[0] - '0';
			yun = 0; index = i;
			for(j = 1; j < l-1; j++) {
				k = index % 3;
				if(k == 0) y = y*10+(str[j] - '0');
				else {			
					if(yun) x-=y;
					else x+=y;
					if(k == 1) yun = 0;
					else yun = 1;
					y = (str[j] - '0');
				}
				index = index/3;
			}
			if(index == 0) {
				y = y*10+(str[j] - '0');
				if(yun) x-=y;
				else x+=y;
			}
			else {
				if(yun) x-=y;
				else x+=y;
				if(index == 1) x+=(str[j] - '0');
				else x-=(str[j] - '0');
			}
			if(x%2==0||x%3==0||x%5==0||x%7==0) re++;
		}		
		printf("Case #%d: %I64d\n",tn+1,re);		
	}
	return 0;
}