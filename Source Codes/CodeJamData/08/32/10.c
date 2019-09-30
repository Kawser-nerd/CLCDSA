#define MAX_LEN 2000


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char input[MAX_LEN+1];

inline int read_line() {
	if (!gets(input)) return -1;
	return (strlen(input));
}

static inline int read_number() {
	read_line(input);
	return (atoi(input));
}

int main() {

	int no_cases, c, i, res, len;

	int calc_ugly(long long val, long long preval, int pos, int len, int sign) {
		if (pos==len) {
			val+=preval*sign;
			return ((val%2==0) || (val%3==0) || (val%5==0) || (val%7==0));
		}

		return 
			calc_ugly(val,10*preval+input[pos],pos+1,len,sign)+
			calc_ugly(val+preval*sign,input[pos],pos+1,len,1)+
			calc_ugly(val+preval*sign,input[pos],pos+1,len,-1);
	}

	no_cases=read_number();
	for (c=0; c<no_cases; c++) {
		len=read_line();
		for(i=0;i<len;input[i++]-='0');
		res=calc_ugly(0,input[0],1,len,1);

		printf("Case #%d: %d\n", c+1, res);
	}
	return 0;
}
