#include <stdio.h>
#include <string.h>

int main(){
	int i, T, j, len, base, v;
	__int64 result;
	char msg[70];
	int fq[128];
	int value[128];
	scanf("%d", &T);
	for(i = 1; i <=T; ++i){
		scanf("%s", msg);
		len = strlen(msg);
		memset(fq, 0, 128 * sizeof(int));
		memset(value, 0, 128 * sizeof(int));
		for(j = 0;j < len; ++j)
			++fq[msg[j]];
		base = 0;
		for(j = 0; j < 128; ++j){
			if (fq[j] > 0)
				++base;
			value[j] = -1;
		}
		if (base==1)
			base = 2;
		value[msg[0]] = 1;
		msg[0] = 1;
		v = 0;
		for(j = 1; j < len; ++j){
			if (value[msg[j]] > -1)
				msg[j] = value[msg[j]];
			else{
				value[msg[j]] = v;
				msg[j] = v;								
				if(v==0)
					v = 2;
				else
					++v;
			}
		}
		result = 1;
		for(j = 1; j < len; ++j)
			result = result * base + msg[j];
		printf("Case #%d: %I64d\n", i, result);
	}
}