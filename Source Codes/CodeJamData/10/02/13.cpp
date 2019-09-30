#include <cstdio>
#include <cstring>

struct bignum {
    int digits[55];
    int length;
};

inline bool gteq(bignum a, bignum b, int n) {
    if(a.length - n > b.length) return true;
    if(a.length - n < b.length) return false;
    for(int i = b.length - 1; i >= 0; i--) {
	if(a.digits[i + n] > b.digits[i]) return true;
	if(a.digits[i + n] < b.digits[i]) return false;
    }
    return true;
}

inline bignum sub(bignum a, bignum b, int n) {
    bignum c;
    c.length = a.length;
    int carry = 0;
    for(int i = 0; i < a.length; i++) {
	c.digits[i] = a.digits[i] - (i-n >= b.length || i-n < 0 ? 0 : b.digits[i-n]) + carry;
	if(c.digits[i] < 0) {
	    carry = -1;
	    c.digits[i] += 10;
	}
	else carry = 0;
    }
    while(c.length > 0 && c.digits[c.length - 1] == 0)
	c.length--;
    return c;
}

inline bignum mod(bignum a, bignum b) {
    for(int i = a.length - 1; i >= b.length - 1; i--) {
	while(gteq(a, b, i - b.length + 1)) {
	    a = sub(a, b, i - b.length + 1);
	}
    }
    return a;
}

inline bignum gcd(bignum a, bignum b) {
    while(a.length > 0 && b.length > 0) {
	if(gteq(a, b, 0)) a = mod(a, b);
	else b = mod(b, a);
    }
    return (a.length == 0 ? b : a);
}

char str[55];
bignum t[1000];

int main() {
    /*bignum a1, a2;
    a1.length = 3;
    a1.digits[0] = 5;
    a1.digits[1] = 4;
    a1.digits[2] = 3;
    a2.digits[1] = 2;
    a2.digits[0] = 1;
    a2.length = 2;
    printf("o.o\n");
    bignum a3 = gcd(a1, a2);
    printf("o.o\n");
    for(int i = a3.length - 1; i >= 0; i--)
	printf("%d", a3.digits[i]);
	printf("\nrawr\n");*/

    int c;
    scanf("%d", &c);
    for(int casenum = 1; casenum <= c; casenum++) {
	int n;
	scanf("%d", &n);
	bignum g;
	g.length = 0;
	for(int i = 0; i < n; i++) {
	    scanf("%s", str);
	    t[i].length = strlen(str);
	    for(int j = 0; j < t[i].length; j++)
		t[i].digits[t[i].length - 1 - j] = (int)(str[j] - '0');
	    if(i > 0) {
		bignum g1 = gteq(t[i], t[i-1], 0) ? sub(t[i], t[i-1], 0) : sub(t[i-1], t[i], 0);
		g = gcd(g, g1);
		//printf("g1: \n");
		//for(int i = g1.length - 1; i >= 0; i--)
		//   printf("%d", g1.digits[i]);
	    }
	}
	//printf("g: \n");
	//for(int i = g.length - 1; i >= 0; i--)
	//    printf("%d", g.digits[i]);
	//printf("\n");
	bignum y = mod(t[0], g);
	if(y.length > 0)
	    y = sub(g, y, 0);
	printf("Case #%d: ", casenum);
	if(y.length == 0)
	    printf("0\n");
	else {
	    for(int i = y.length - 1; i >= 0; i--)
		printf("%d", y.digits[i]);
	    printf("\n");
	}
    }
}
