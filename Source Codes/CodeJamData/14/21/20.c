#include <stdio.h>

int main() {

	int t, _t;
	scanf("%d", &t);

	for ( _t = 0; _t < t; ++_t ) {
		int n;
		scanf("%d", &n);
		char str1[1000];
		char str2[1000];
		scanf("%s %s", str1, str2);
		int len1 = strlen(str1);
		int len2 = strlen(str2);
		int i, j;

		int count1[107];
		int count2[107];
		char what1[107];
		char what2[107];
		memset(count1, 0, sizeof(count1));
		memset(count2, 0, sizeof(count2));
		memset(what1, 0, sizeof(what1));
		memset(what2, 0, sizeof(what2));

		int last = 1;
		int last1 = 0;
		for ( i = 1; i < len1; ++i ) {
			if ( str1[i] == str1[i-1] )
				++last;
			else {
				count1[last1++] = last;
				what1[last1-1] = str1[i-1];
				last = 1;
			}
		}
		if ( len1 == 1 || last ) {
			count1[last1++] = last;
			what1[last1-1] = str1[i-1];
		}

		last = 1;
		int last2 = 0;
		for ( i = 1; i < len2; ++i ) {
			if ( str2[i] == str2[i-1] )
				++last;
			else {
				count2[last2++] = last;
				what2[last2-1] = str2[i-1];
				last = 1;
			}
		}
		if ( len2 == 1 || last ) {
			count2[last2++] = last;
			what2[last2-1] = str2[i-1];
		}

		if ( strcmp(what1, what2) != 0 ) {
			printf("Case #%d: Fegla Won\n", _t+1);
			continue;
		}

		int ret = 0;
		for ( i = 0; i < last2; ++i ) {
			ret += abs(count1[i] - count2[i]);
		}

		printf("Case #%d: %d\n", _t+1, ret);
	}

	return 0;

}
