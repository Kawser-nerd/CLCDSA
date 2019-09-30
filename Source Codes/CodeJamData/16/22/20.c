#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int c, j, diff;
char C[4], J[4];
int length;

int c_match() {
	int i, temp;
	if(!c) {
		for(i = 0; i < length; ++i) {
			if(C[i] != '0' && C[i] != '?')
				return 0;
		}
		return 1;
	}
	else {
		temp = c;
		for(i = length-1; i >= 0; --i) {
			if(C[i]-'0' != temp%10 && C[i] != '?')
				return 0;
			temp /= 10;
		}
		return temp ? 0 : 1;
	}
}

int j_match() {
	int i, temp;
	if(!j) {
		for(i = 0; i < length; ++i) {
			if(J[i] != '0' && J[i] != '?')
				return 0;
		}
		return 1;
	}
	else {
		temp = j;
		for(i = length-1; i >= 0; --i) {
			if(J[i]-'0' != temp%10 && J[i] != '?')
				return 0;
			temp /= 10;
		}
		return temp ? 0 : 1;
	}	
}

int main() {
	int t, tc=1;
	int _c, _j;
	scanf("%d", &t);
	while(t--) {
		scanf("%s %s", C, J);
		length = strlen(C);
		diff = 1001;
		for(c = 0; diff && c < 1000; ++c) {
			if(c_match()) {			
				for(j = 0; diff && j < 1000; ++j) {
					if(j_match()) {
						if(abs(c-j) < diff) {
							diff = abs(c-j);
							_c = c;
							_j = j;
						}
						else if(abs(c-j) == diff) {
							if(j < _j) {
								
							}
						}
					}
				}
			}
		}
		printf("Case #%d: %0*d %0*d\n", tc++, length, _c, length, _j);
	}
	return 0;
}
