#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define LEN 210

typedef struct {
	char digits[LEN];
	int sinal, len;
} Bignum;

Bignum* zera(Bignum *n);
Bignum* create_int(int nro, Bignum *n);
Bignum* create(char *s, int tams, Bignum *n);
Bignum* copy(Bignum *n1, Bignum *n2);
Bignum* no_zeroes(Bignum *n);
void shift(Bignum *n, int casas);
int compare(Bignum *n1, Bignum *n2);
Bignum* print(Bignum *n);

Bignum* add_one(Bignum *n);
Bignum* minus_one(Bignum *n);
Bignum* add(Bignum *nro1, Bignum *nro2, Bignum *r);
Bignum* subtract(Bignum *a, Bignum *b, Bignum *r);
Bignum* mult_int(Bignum *nro, int temp, Bignum *r);
Bignum* multiply(Bignum *nro1, Bignum *nro2, Bignum *r);
Bignum* div_int(Bignum *n1, int d, Bignum *r, int *resto);
Bignum* divide(Bignum *n1, Bignum *n2, Bignum *r);
Bignum* modulus(Bignum *n1, Bignum *n2, Bignum *r);
Bignum* pow_int(Bignum *n, int p, Bignum *r);
Bignum* power(Bignum *base, Bignum *exp, Bignum *r);
Bignum* square_root(Bignum *n, Bignum *r);

Bignum zero, one;

void gcd(Bignum *a, Bignum *b, Bignum *c) {
	Bignum x;
	if (compare(b,&zero) == 0) {
		copy(c,a);
	}
	else {
		gcd(b,modulus(a,b,&x),c);
	}
}

Bignum v[1005];

int main() {
	int t, caso = 1;
	int n, i;
	char s[LEN+1];
	Bignum diff, aux1, aux2, ans;
	
	create_int(0,&zero);
	create_int(1,&one);
	
	scanf("%d",&t);
	
	while (t--) {
		scanf("%d",&n);
		for (i=0; i < n; i++) {
			scanf("%s",s);
			create(s,strlen(s),&v[i]);
		}
		
		qsort(v,n,sizeof(Bignum),(void*)compare);
		
		subtract(&v[1],&v[0],&diff);
		for (i=2; i < n; i++) {
			subtract(&v[i],&v[i-1],&aux1);
			gcd(&aux1,&diff,&aux2);
			copy(&diff,&aux2);
		}
		
		if (compare(&diff,&one) == 0) {
			copy(&ans,&zero);
		}
		else {
			modulus(&v[0],&diff,&aux1);
			subtract(&diff,&aux1,&aux2);
			modulus(&aux2,&diff,&ans);
		}
		
		printf("Case #%d: ",caso++);
		print(&ans);
		puts("");
	}
	
	return 0;
}

Bignum* zera(Bignum *n) {
	n->digits[0] = '0';
	n->digits[1] = '\0';
	n->len = n->sinal = 1;
	return n;
}

Bignum* create(char *s, int tams, Bignum *n) {
	int pos,pos2,ajuste,inicio;
	
	n->len = tams;
	n->sinal = 1;
	if (s[0] == '-') {
		n->sinal = -1;
		n->len--;
	}
	ajuste = (n->sinal == -1)?1:0;
	
	for (pos=ajuste; pos < tams; pos++)
		if (s[pos] != '0')
			break;
	if (pos == tams)
		return zera(n);
	if (pos != ajuste)
		n->len -= pos-ajuste;
	inicio = pos;
	
	for (pos=0,pos2=tams-1; pos2 >= inicio; pos++,pos2--)
		n->digits[pos] = s[pos2];
	n->digits[n->len] = '\0';
	
	return n;
}

Bignum* create_int(int nro, Bignum *n) {
	int pos;
	n->sinal = 1;
	if (nro < 0)
		n->sinal = -1, nro = -nro;
	n->digits[0] = '0';
	for (pos=0; nro; pos++,nro/=10)
		n->digits[pos] = nro%10 + '0';
	n->len = (pos == 0) ? 1 : pos;
	return n;
}

Bignum* copy(Bignum *n1, Bignum *n2) {
	memcpy(n1,n2,sizeof(Bignum));
	return n1;
}

Bignum* no_zeroes(Bignum *n) {
	int pos;
	for (pos=n->len-1; pos > 0 && n->digits[pos] == '0'; pos--,n->len--);
	n->digits[n->len] = '\0';
	if (pos == 0 && n->digits[0] == '0')
		n->sinal = 1;
	return n;
}

int compare(Bignum *n1, Bignum *n2) {
	int pos;
	if (n1->len != n2->len)
		return n1->len*n1->sinal - n2->len*n2->sinal;
	for (pos=n1->len-1; pos > -1; pos--) {
		if (n1->digits[pos] != n2->digits[pos])
			return n1->digits[pos]*n1->sinal - n2->digits[pos]*n2->sinal;
	}
	return 0;
}

Bignum* print(Bignum *n) {
	int pos;
	if (n->sinal == -1)
		printf("-");
	for (pos=0; pos < n->len; pos++)
		printf("%c",n->digits[n->len-pos-1]);
	return n;
}

Bignum* add_one(Bignum *n) {
	int pos;
	for (pos=0; pos < n->len && n->digits[pos] == '9'; pos++)
		n->digits[pos] = '0';
	if (pos == n->len) {
		n->digits[n->len] = '1';
		n->len++;
	}
	else
		n->digits[pos]++;
	return n;
}

Bignum* minus_one(Bignum *n) {
	int pos;
	for (pos=0; pos < n->len && n->digits[pos] == '0'; pos++)
		n->digits[pos] = '9';
	if (pos == n->len)
		n->len--;
	else
		n->digits[pos]--;
	return n;
}

Bignum* add(Bignum *nro1, Bignum *nro2, Bignum *r) {
	int pos, aux, lim, vai1 = 0, sinal1, sinal2;
	
	if (nro1->sinal != nro2->sinal) {
		sinal1 = nro1->sinal, nro1->sinal = 1;
		sinal2 = nro2->sinal, nro2->sinal = 1;
		if (compare(nro1,nro2) > 0) {
			subtract(nro1,nro2,r);
			r->sinal = sinal1;
		}
		else {
			subtract(nro2,nro1,r);
			r->sinal = sinal2;
		}
		nro1->sinal = sinal1, nro2->sinal = sinal2;
		return r;
	}
	
	r->len = (nro1->len > nro2->len)?nro1->len:nro2->len;
	lim = (nro1->len < nro2->len)?nro1->len:nro2->len;
	
	for (pos=0; pos < lim; pos++) {
		aux = nro1->digits[pos] + nro2->digits[pos] - 96 + vai1;
		r->digits[pos] = aux%10 + 48;
		vai1 = (aux > 9)?1:0;
	}
	if (lim == nro2->len) {
		for ( ; pos < nro1->len; pos++) {
			aux = nro1->digits[pos] - 48 + vai1;
			r->digits[pos] = aux%10 + 48;
			vai1 = (aux > 9)?1:0;
		}
	}
	else {
		for ( ; pos < nro2->len; pos++) {
			aux = nro2->digits[pos] - 48 + vai1;
			r->digits[pos] = aux%10 + 48;
			vai1 = (aux > 9)?1:0;
		}
	}
	if (vai1)
		r->digits[r->len++] = '1';
	r->sinal = nro1->sinal;
	r->digits[r->len] = '\0';
	
	return r;
}

Bignum* mult_int(Bignum *nro, int temp, Bignum *r) {
	int pos, vai, aux;
	
	zera(r);
	r->len = nro->len;
	r->sinal = nro->sinal;
	if (temp == 0)
		return zera(r);
	if (temp < 0) {
		r->sinal *= -1;
		temp = -temp;
	}
	for (pos=vai=0; pos < nro->len; pos++) {
		aux = (nro->digits[pos]-48)*temp + vai;
		r->digits[pos] = aux%10 + 48;
		vai = aux/10;
	}
	for ( ; vai; vai/=10)
		r->digits[r->len++] = vai%10 + 48;
	r->digits[r->len] = '\0';
	
	return r;
}

void shift(Bignum *n, int casas) {
	int pos;
	for (pos=n->len-1; pos > -1; pos--)
		n->digits[pos+casas] = n->digits[pos];
	for (pos=0; pos < casas; pos++)
		n->digits[pos] = '0';
	n->len += casas;
}

Bignum* multiply(Bignum *nro1, Bignum *nro2, Bignum *r) {
	Bignum temp[2];
	int pos;
	zera(&temp[0]); zera(&temp[1]), zera(r);
	for (pos=0; pos < nro2->len; pos++) {
		zera(&temp[0]);
		mult_int(nro1,nro2->digits[pos]-48,&temp[0]);
		shift(&temp[0],pos);
		no_zeroes(&temp[0]);
		add(&temp[0],r,&temp[1]);
		copy(r,&temp[1]);
	}
	r->sinal = nro1->sinal*nro2->sinal;
	no_zeroes(r);
	return r;
}

Bignum* subtract(Bignum *a, Bignum *b, Bignum *r) {
	int sinala, sinalb, pediu, pos;
	
	zera(r);
	if (a->sinal != b->sinal) {
		b->sinal = a->sinal;
		add(a,b,r);
		b->sinal = a->sinal*-1;
		r->sinal = a->sinal;
		return r;
	}
	
	sinala = a->sinal;
	sinalb = b->sinal;
	a->sinal = b->sinal = 1;
	if (compare(a,b) < 0) {
		a->sinal = sinala;
		b->sinal = sinalb;
		subtract(b,a,r);
		r->sinal = -1*a->sinal;
		return r;
	}
	a->sinal = sinala;
	b->sinal = sinalb;
	pediu = 0;
	for (pos=0; pos < b->len; pos++) {
		if (a->digits[pos]-pediu < b->digits[pos]) {
			r->digits[pos] = a->digits[pos] + 10 - pediu - b->digits[pos] + '0';
			pediu = 1;
		}
		else {
			r->digits[pos] = a->digits[pos] - pediu - b->digits[pos] + '0';
			pediu = 0;
		}
	}
	for ( ; pos < a->len; pos++) {
		if (a->digits[pos]-pediu < '0') {
			r->digits[pos] = a->digits[pos] - pediu + 10;
			pediu = 1;
		}
		else {
			r->digits[pos] = a->digits[pos] - pediu;
			pediu = 0;
		}
	}
	for (r->len=a->len-1; r->len > -1 && r->digits[r->len] == '0'; r->len--);
	r->len = (r->len == -1)?1:r->len+1;
	r->digits[r->len] = '\0';
	r->sinal = a->sinal;
	
	return r;
}

Bignum* div_int(Bignum *n1, int d, Bignum *r, int *resto) {
	int pos, pos2;
	r->len = n1->len;
	if ((n1->digits[n1->len-1]-'0')/d == 0)
		r->len -= 1;
	*resto = 0;
	for (pos=n1->len-1; pos > -1; pos--,pos2--) {
		*resto *= 10;
		r->digits[pos] = (*resto + n1->digits[pos]-'0')/d + '0';
		*resto = (*resto + n1->digits[pos]-'0')%d;
	}
	if (r->len == 0)
		r->len = 1, r->digits[0] = '0';
	r->sinal = 1;
	return no_zeroes(r);
}

Bignum* divide(Bignum *n1, Bignum *n2, Bignum *r) {
	Bignum temp, aux;
	int pos, tamr = 0, n, sinal1, sinal2;
	char buffer[LEN];
	
	sinal1 = n1->sinal, sinal2 = n2->sinal;
	n1->sinal = n2->sinal = 1;
	zera(&temp);
	for (pos=n1->len-1; pos > -1; ) {
		while (pos > -1 && compare(&temp,n2) < 0) {
			shift(&temp,1), no_zeroes(&temp);
			temp.digits[0] = n1->digits[pos--];
			if (compare(&temp,n2) < 0)
				buffer[tamr++] = '0';
		}
		if (compare(&temp,n2) >= 0) {
			for (n=0; compare(&temp,n2) >= 0; n++) {
				subtract(&temp,n2,&aux);
				copy(&temp,&aux);
			}
			buffer[tamr++] = n + '0';
		}
	}
	buffer[tamr] = '\0';
	create(buffer,tamr,r);
	n1->sinal = sinal1, n2->sinal = sinal2;
	if (r->len != 1 || r->digits[0] != '0')
		r->sinal = n1->sinal * n2->sinal;
	
	return r;
}

Bignum* modulus(Bignum *n1, Bignum *n2, Bignum *r) {
	Bignum aux1, aux2;
	return subtract(n1,multiply(divide(n1,n2,&aux1),n2,&aux2),r);
}

Bignum* power_int(Bignum *n, int p, Bignum *r) {
	Bignum temp, aux;
	if (p == 0) return create_int(1,r);
	if (p == 1) return copy(r,n);
	power_int(n,p/2,&temp);
	if (p&1)
		return multiply(multiply(&temp,&temp,&aux),n,r);
	return multiply(&temp,&temp,r);
}

Bignum* power(Bignum *base, Bignum *exp, Bignum *r) {
	Bignum aux1, aux2;
	int resto;
	if (exp->len == 1 && exp->digits[0] == '0')
		return create_int(1,r);
	if (exp->len == 1 && exp->digits[0] == '1')
		return copy(r,base);
	div_int(exp,2,&aux1,&resto);
	power(base,&aux1,&aux2);
	if (resto == 0)
		return multiply(&aux2,&aux2,r);
	return multiply(multiply(&aux2,&aux2,&aux1),base,r);
}

Bignum* square_root(Bignum *n, Bignum *r) {
	Bignum temp, resto, r1, r2;
	char buffer[LEN];
	int pos, pos2, tambuf, aux;
	
	temp.sinal = resto.sinal = 1;
	if (n->len%2 == 1)
		n->digits[n->len++] = '0';
	aux = (int) (sqrt((n->digits[n->len-1] - '0')*10 + n->digits[n->len-2]-'0') + 1.0e-7);
	create_int((n->digits[n->len-1] - '0')*10 + n->digits[n->len-2]-'0' - aux*aux,&resto);
	buffer[0] = aux + '0';
	tambuf = 1;
	
	for (pos=n->len-3; pos > -1; pos-=2) {
		shift(&resto,2);
		resto.digits[1] = n->digits[pos], resto.digits[0] = n->digits[pos-1];
		no_zeroes(&resto);
		mult_int(create(buffer,tambuf,&temp),2,&r1);
		shift(copy(&temp,&r1),1);
		for (pos2=1; pos2 < 10; pos2++) {
			temp.digits[0] = pos2 + '0';
			if (compare(mult_int(&temp,pos2,&r1),&resto) > 0)
				break;
		}
		buffer[tambuf++] = pos2 - 1 + '0';
		temp.digits[0] = pos2 - 1 + '0';
		copy(&resto,subtract(&resto,mult_int(&temp,pos2-1,&r1),&r2));
	}
	create(buffer,tambuf,r);
	no_zeroes(n);
	
	return r;
}
