#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define REP(i,a) for(int i = 0,_n = (a);i < _n;++i)
#define FORD(i,a,b) for(int i = (a),_n = (b);i >= _n;--i)

// reprezentacja - bez zer wiodacych, cyfry od najmniej znaczacej

// domyslna baza
const int BASE = 10000;
// maksymalna liczba cyfr dla liczby wczytywanej przez scandata i scan_signed
const int STRINGMAX = 100;
// jesli baza jest potega dziesiatki, liczba cyfr przypadajacych na jednego inta
// log_10 (BASE), uzywane przez scan... i print...
const int CYPHS_PER_INT = 4;

// tablica dla danych wejsciowych - uzywane przez scan...
char str[STRINGMAX+2];

inline int* strip(int* b,int* e) {
	while (e != b && *(e-1) == 0)
		--e;
	return e;
}

// wczytywanie, dane w systemie dziesietnym, '0'..'9', DBASE potega dziesiatki
// obsluguje zera wiodace
// czas: O(n)
// pamiec na b: ceil (log_BASE (p+1))
int* scandata(int* b) {
	scanf("%s",str);
	const char *bstr = str;
	while (*bstr == '0') ++bstr;
	int n = strlen(bstr);
	
	int stage = 0,packet = 0,mnoznik = 1;
	FORD(i,n-1,0) {
		packet += (bstr[i]-'0')*mnoznik;
		if (++stage == CYPHS_PER_INT) {
			*b++ = packet;
			mnoznik = 1;
			packet = stage = 0;
		} else mnoznik *= 10;
	}
	if (stage != 0) *b++ = packet;
	return b;
}

// wypisywanie w systemie dziesietnym '0'..'9'
// czas: O(n)
void printdata(const int* b,const int* e) {
	if (e==b) putchar('0');
	else printf("%d",*--e);
	while (e != b)
	// TUTAJ WSTAWIC CYPHS_PER_INT
		printf("%04d",*--e);
}

inline void add_step(int* res,int cyf,int& carry,int DBASE) {
	cyf >= DBASE ? carry = 1, cyf -= DBASE : carry = 0;
	*res = cyf;
}
// dodawanie dwoch BigNumow (p1+p2)
// res moze byc rowne b1 lub b2
// czas: O(n1+n2)
// pamiec na res: max(n1,n2)+1
int *add(const int* b1,const int* e1,const int* b2,const int* e2,int* res,int DBASE=BASE) {
	if (e1-b1 < e2-b2) {
		swap(b1,b2); swap(e1,e2);
	}
	int carry = 0;
	while(b2 != e2)
		add_step(res++,*b1++ + *b2++ + carry,carry,DBASE);
	while (b1 != e1)
		add_step(res++,*b1++ + carry,carry,DBASE);
	if (carry) *res++ = carry;
	return res;
}

inline void sub_step(int* res,int cyf,int& carry,int DBASE) {
	cyf < 0 ? carry = -1, cyf += DBASE : carry = 0;
	*res = cyf;
}
// odejmowanie dwoch BigNumow (p1-p2)
// IN: p1 >= p2
// res moze byc rowne b1 lub b2
// czas: O(n1+n2)
// pamiec na res: n1
int* subtract(const int* b1,const int* e1,const int* b2,const int* e2,int* res,int DBASE=BASE) {
	int *rstart = res, carry = 0;
	while (b2 != e2)
		sub_step(res++,*b1++ - *b2++ + carry,carry,DBASE);
	while (b1 != e1)
		sub_step(res++,*b1++ + carry,carry,DBASE);
	return strip(rstart,res);
}

inline void mul_step(const int* b,const int* e,int cyf,int* res,int DBASE) {
	if (cyf == 0) return;
	int carry = 0;
	while (b != e) {
		// TU ZMIENIC JESLI BAZA^2 NIE MIESCI SIE W INT
		carry += cyf * *b++ + *res;
		*res++ = carry % DBASE;
		carry /= DBASE;
	}
	if (carry) *res++ = carry;
}
// mnozenie dwoch BigNumow (p1*p2)
// res NIE moze byc rowne b1 ani b2
// czas: O(n1*n2)
// pamiec na res: n1+n2
int* multiply(const int* b1,const int* e1,const int* b2,const int* e2,int* res,int DBASE=BASE) {
	int *rbeg = res, n = (e1-b1)+(e2-b2);
	fill_n(res,n,0);
	while (b2 != e2)
		mul_step(b1,e1,*b2++,res++,DBASE);
	return strip(rbeg,rbeg+n);
}

// porownujemy wartosci bezwzgledne >0 => L wieksza, 0 => rowne, <0 => R wieksza
// czas: O(min(n1,n2))
inline int modcmp(const int* b1,const int* e1,const int* b2,const int* e2) {
	if (e1-b1 != e2-b2)
		return (e1-b1) - (e2-b2);
	while (b1 != e1)
		if (*--e1 != *--e2)
			return *e1-*e2;
	return 0;
}


// dzielenie przez 2, (p / 2)
// baza musi byc parzysta
// res moze byc rowne b
// czas: O(n)
// pamiec na res: n
int* div2(const int *b, const int *e, int *res,int DBASE=BASE) {
	int n=e-b,caro=0,carn;
	res += n;
	while (e-- != b) {
		carn = *e % 2;
		*--res = *e/2;
		if (caro) *res += DBASE/2;
		caro = carn;
	}
	return strip(res,res+n);
}

// reszta z dzielenia BigNumow (p1 % p2)
// p2 != 0
// res moze byc rowny b1
// czas: O(n1^2)
// pamiec na res: 2*n1+1
int* modulo(const int* b1,const int *e1,const int *b2,const int *e2,int* res,int DBASE=BASE) {
	if (b1 != res) copy(b1,e1,res);
	if (e1-b1 < e2-b2) return res+(e1-b1);
	int *eres = res+(e1-b1), *btmp = eres, *etmp = copy(b2,e2,btmp);
	while (modcmp(res,eres,btmp,etmp) > 0)
		etmp = add(btmp,etmp,btmp,etmp,btmp,DBASE);
	while (modcmp(res,eres,b2,e2) >= 0) {
		if (modcmp(res,eres,btmp,etmp) >= 0)
			eres = subtract(res,eres,btmp,etmp,res,DBASE);
		etmp = div2(btmp,etmp,btmp,DBASE);
	}
	return eres;
}

// dzielenie z reszta dwoch BigNumow (p1 / p2)
// p2 != 0
// [b1,e1) - p1,  [b2,e2) - p2,  res - iloraz, [bmod,emod) - reszta
// res NIE moze byc rowne b1 ani b2; mod moze byc rowne b1
// czas: O(n1^2)
// pamiec mod - n1, res - 3*n1+3
int* divide(const int* b1,const int *e1,const int *b2,const int *e2,int *res,int *bmod,int *&emod,int DBASE=BASE) {
	emod = (bmod != b1) ? copy(b1,e1,bmod) : bmod+(e1-b1);
	if (e1-b1 < e2-b2) return res;
	// bt1 - wynik, bt2 - dzielnik*2^i, bt3 - 2^i
	int *bt1 = res, *et1 = bt1, *bt2 = bt1+(e1-b1), *et2 = copy(b2,e2,bt2);
	int *bt3 = bt2+(e1-b1)+1, *et3 = bt3+1;
	*bt3 = 1;
	
	while (modcmp(bmod,emod,bt2,et2) > 0) {
		et2 = add(bt2,et2,bt2,et2,bt2,DBASE);
		et3 = add(bt3,et3,bt3,et3,bt3,DBASE);
	}
	while (modcmp(bmod,emod,b2,e2) >= 0) {
		if (modcmp(bmod,emod,bt2,et2) >= 0) {
			et1 = add(bt1,et1,bt3,et3,bt1,DBASE);
			emod = subtract(bmod,emod,bt2,et2,bmod,DBASE);
		}
		et2 = div2(bt2,et2,bt2,DBASE);
		et3 = div2(bt3,et3,bt3,DBASE);
	}
	return et1;
}

// dzielenie z reszta BigNuma przez inta (p / m)
// m != 0
// [b,e) - p,  m - dzielnik,  res - iloraz,  mod - reszta
// res moze byc rowne b
// czas: O(n)
// pamiec na res - n
// jesli DBASE*m nie miesci sie w incie trzeba rzutowac na long longi
int* divide_int(const int *b,const int *e,int m,int* res,int& mod,int DBASE=BASE) {
	int n=e-b, *eres = res+n;
	mod = 0;
	while (b != e) {
		mod *= DBASE;
		mod += *--e;
		*--eres = mod / m;
		mod %= m;
	}
	return strip(res,res+n);
}

// konwersja BigNuma z OBASE --> DBASE
// IN: BigNum [b,e),  res - wynik,  tmp - miejsce na obliczenia
// res NIE moze byc rowne b
// czas: O(n^2)
// pamiec na res: ~ n * (1+log_DBASE (OBASE))
int *change_base(const int *b,const int *e,int *res,int OBASE,int DBASE=BASE) {
	int* tmp = res, *etmp = copy(b,e,tmp), *bres = etmp, *eres = bres;
	while (tmp != etmp)
		etmp = divide_int(tmp,etmp,DBASE,tmp,*eres++,OBASE);
	return copy(bres,eres,res);
}

// podstawa - wykladnik - modulo !=0
// res nie moze nakladac sie na zaden z argumentow
// pamiec na res: 4*n3+2 + max(8*n3+n2+1,2*n1)
int* moduloexp(const int* b1,const int *e1,const int *b2,const int *e2,const int *b3,const int *e3,int *res,int DBASE=BASE) {
	// bt1 - wynik, bt2 - a^(2^i), bt3 - wykladnik dzielony przez2, bt4 - temp
	int n = e3-b3, *bt1 = res, *bt2 = res+4*n+1, *bt3 = bt2+4*n+1, *bt4 = bt3+(e2-b2);
	int *et1 = bt1+1, *et2 = modulo(b1,e1,b3,e3,bt2,DBASE), *et3 = copy(b2,e2,bt3), *et4;
	*bt1 = (e3 == b3+1 && *b3 == 1 ? 0 : 1);

	while (bt3 != et3) {
		if (*bt3 % 2 == 1) {
			et4 = multiply(bt1,et1,bt2,et2,bt4,DBASE);
			et4 = modulo(bt4,et4,b3,e3,bt4,DBASE);
			swap(bt1,bt4);	swap(et1,et4);
		}
		et4 = multiply(bt2,et2,bt2,et2,bt4,DBASE);
		et4 = modulo(bt4,et4,b3,e3,bt4,DBASE);
		swap(bt2,bt4);	swap(et2,et4);
		et3 = div2(bt3,et3,bt3,DBASE);
	}
	if (bt1 != res) copy(bt1,et1,res);
	return res+(et1-bt1);
}

// s - false:ujemna, true:dodatnia
int* scan_signed(int* b,bool& s) {
	char buf[2];
	scanf("%1s",buf);
	if (*buf == '-') s = false;
	else { ungetc(*buf,stdin); s = true; }
	int *res = scandata(b);
	if (res == b) s = true;
	return res;
}
void print_signed(int* b,int* e,bool s) {
	if (!s) putchar('-');
	printdata(b,e);
}
// res moze byc rowny b1 lub b2
int* subtract_signed(const int* b1,const int* e1,bool s1,const int* b2,const int* e2,bool s2,int* res,bool& rs,int DBASE=BASE) {
	if (s1 != s2) {
		rs = s1;
		return add(b1,e1,b2,e2,res,DBASE);
	} else {
		int cmp = modcmp(b1,e1,b2,e2);
		if (cmp > 0) rs = s1;
		else if (cmp < 0) rs = !s1;
		else rs = true;
		return (cmp >= 0) ? subtract(b1,e1,b2,e2,res,DBASE)
			: subtract(b2,e2,b1,e1,res,DBASE);
		
	}
}
// res moze byc rowny b1 lub b2
int* add_signed(const int * b1,const int* e1,bool s1,const int* b2,const int* e2,bool s2,int* res,bool& rs,int DBASE=BASE) {
	return subtract_signed(b1,e1,s1,b2,e2,b2==e2?true:!s2,res,rs,DBASE);
}
// res nie moze byc rowne b1 ani b2
int* multiply_signed(const int* b1,const int* e1,bool s1,const int* b2,const int* e2,bool s2,int* res,bool& rs,int DBASE=BASE) {
	rs = (s1 == s2);
	if (b1 == e1 || b2 == e2) rs = true;
	return multiply(b1,e1,b2,e2,res,DBASE);
}

// egcd - [b1,e1), [b2,e2) liczby, res - poczatek wyniku, zwraca przedzial [res,x,y,ret), sx, sy - znaki x i y
// w tym przedziale mamy kolejno wynik, x i y (x*p1 + y*p2 = res)
// res NIE moze sie nakladac na argumenty
int *egcd(const int *b1,const int *e1,const int *b2,const int *e2,int *res,int *&x,int *&y,bool& sx,bool& sy,int DBASE=BASE) {
	if (b2 == e2) {
		sx = sy = true;
		x = copy(b1,e1,res);
		*x = 1;
		return y = x+1;
	}
	
	int n1 = e1-b1, n2 = e2-b2;
	// [bt1,et1) - reszta, [bt2,et2) - dzielenie
	bool stx,sty,tmp;
	int *e, *bt1 = res+n1+n2+min(n1,n2)+1, *et1, *bt2=bt1+(n1), *et2 = divide(b1,e1,b2,e2,bt2,bt1,et1,DBASE);
	int *bt3 = et2, *tx, *ty, *et3 = egcd(b2,e2,bt1,et1,bt3,tx,ty,stx,sty,DBASE);
	x = copy(bt3,tx,res);
	y = copy(ty,et3,x);
	e = copy(tx,ty,y);
	sx = sty, sy = stx;
	et3 = multiply_signed(x,y,sx,bt2,et2,true,bt3,tmp,DBASE);
	e = subtract_signed(y,e,sy,bt3,et3,tmp,y,sy,DBASE);
	return e;
}

// ----------------------------------------------------------------------------

const int NUMMAX = 15, NMAX = 1000;
int T[NMAX][NUMMAX], *eT[NMAX];
int diff[NMAX-1][NUMMAX], *ediff[NMAX-1];
int res[NMAX];

void testcase(int t) {
	int N;
	scanf("%d",&N);
	REP(i,N) eT[i] = scandata(T[i]);
	int nd = 0;
	REP(i,N-1) {
		int left = 0, right = i+1;
		int cmp = modcmp(T[left],eT[left],T[right],eT[right]);
		if (cmp == 0) continue;
		if (cmp < 0) swap(left,right);
		ediff[nd] = subtract(T[left],eT[left],T[right],eT[right],diff[nd]);
		++nd;
	}
	
	int *cur = res, *ecur = copy(diff[0],ediff[0],cur);
	for(int i = 1;i < nd;++i) {
		int *x, *y;
		bool sx, sy;
		int *tmp = ecur, *etmp = egcd(cur,ecur,diff[i],ediff[i],tmp,x,y,sx,sy);
		cur = tmp, ecur = x;
	}
	
	int *div = ecur, *ediv = divide(T[0],eT[0],cur,ecur,div,T[0],eT[0]);
	if (T[0] != eT[0])
		eT[0] = subtract(cur,ecur,T[0],eT[0],T[0]);
	printf("Case #%d: ",t);
	printdata(T[0],eT[0]);
	putchar('\n');
}

int main() {
	int C;
	scanf("%d",&C);
	for(int i = 1;i <= C;++i)
		testcase(i);
}
