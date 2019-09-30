#include <stdio.h>
#include <string.h>

char input[1000004];
int startNum;
int startList[1000010];

int main(void) {
	int T,caseCount;
	scanf("%d",&T);
	for(caseCount=1;caseCount<=T;caseCount++) {
		int n;
		int len;
		int nowRenzoku;
		int i;
		long long result;
		scanf("%s%d",input,&n);
		len=strlen(input);
		startNum=1;
		startList[0]=-1;
		nowRenzoku=0;
		for(i=0;i<len;i++) {
			if(input[i]=='a' || input[i]=='i' || input[i]=='u' ||
				input[i]=='e' || input[i]=='o')nowRenzoku=0;
			else nowRenzoku++;
			if(nowRenzoku>=n)startList[startNum++]=i-n+1;
		}
		result=0;
		for(i=1;i<startNum;i++) {
			long long start=startList[i]-startList[i-1];
			long long end=len-startList[i]-n+1;
			result+=start*end;
		}
		printf("Case #%d: %lld\n",caseCount,result);
	}
	return 0;
}
