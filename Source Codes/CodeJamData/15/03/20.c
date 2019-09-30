#include <stdio.h>
#include <string.h>

//1 == 1
//i == 2
//j == 3
//k == 4

const int m[5][5] = {{0,0,0,0,0}, {0,1,2,3,4}, {0,2,-1,4,-3}, {0,3,-4,-1,2}, {0,4,3,-2,-1}};

int multiply(int a, int b) {
	if(a < 0)
		if(b < 0)
			return m[abs(a)][abs(b)];
		else
			return -m[abs(a)][b];
	else
		if(b < 0)
			return -m[a][abs(b)];
		else
			return m[a][b];
}


char str[10001], str2[10001];
int rend[10001], rbegin[10001];
int resend[10001], rcont;

int checkresend(int a) {
	int j;
	if(a < rcont) {
		for(j=rcont-1; j >= a; j--) {
			resend[j] = multiply((str2[j] == 'i' ? 2 : (str2[j] == 'j' ? 3 : 4)), resend[j+1]);
		}
	}
	rcont=a;
	return resend[a] == 4;
}

int main() {
	int n, x, /*l,*/ i, j, k, s, /*a, b, c,*/ res, res2, yes/*, max*/;
	long long int l, max, a, b, c;

	scanf("%d", &n);
	for(i=0; i < n; i++) {
		scanf("%d%lld", &x, &l);
		scanf("%s", str);

		if(l >= 2) {
			rbegin[0] = 1;
			for(j=1; j <= x; j++)
				rbegin[j] = multiply(rbegin[j-1], (str[j-1] == 'i' ? 2 : (str[j-1] == 'j' ? 3 : 4)));
			rend[x] = 1;
			for(j=x-1; j >= 0; j--)
				rend[j] = multiply((str[j] == 'i' ? 2 : (str[j] == 'j' ? 3 : 4)), rend[j+1]);

			int CC[4];
			CC[0] = 1;
			CC[1] = multiply(CC[0],rbegin[x]);
			CC[2] = multiply(CC[1],rbegin[x]);
			CC[3] = multiply(CC[2],rbegin[x]);

			max=l-2;
			yes=0;
			for(j=0; j <= x && !yes; j++) {
				for(a=0; a < 4 && a <= max && !yes; a++) {
					if(multiply(CC[a],rbegin[j]) == 2) {
						for(k=0; k <= x && !yes; k++) {
							for(b=0; b < 4 && a+b <= max && !yes; b++) {
								if(multiply(multiply(rend[j],CC[b]),rbegin[k]) == 3)
									for(c=0; c < 4 && a+b+c <= max && !yes; c++)
										if((a+b+c)%4 == max%4 && multiply(rend[k],CC[c]) == 4) {
											yes=1;
//											printf("%d %d %d -> %d %d\n", a, b, c, j, k);
										}
							}
						}
					}
				}
			}

			if(yes)
				printf("Case #%d: YES\n", i+1);
			else
				printf("Case #%d: NO\n", i+1);
		}
		else {
			str2[0] = '\0';
			for(j=0; j < l; j++)
				strcat(str2, str);
			s=x*l;

			yes=0;
			res=1;
			rcont=s;
			resend[rcont]=1;
			for(j=0; j < s && !yes; j++) {
				res = multiply(res,(str2[j] == 'i' ? 2 : (str2[j] == 'j' ? 3 : 4)));
				if(res == 2) {
	//				printf("%.*s\n", j+1, str2);
					res2=1;
					for(k=j+1; k < s-1 && !yes; k++) {
						res2 = multiply(res2,(str2[k] == 'i' ? 2 : (str2[k] == 'j' ? 3 : 4)));
						if(res2 == 3) {
	//						printf(">>> %.*s\n", k+1, str2);
							if(checkresend(k+1))
								yes=1;
						}
					}
				}
			}
			if(yes)
				printf("Case #%d: YES\n", i+1);
			else
				printf("Case #%d: NO\n", i+1);
		}
	}
}

