#include<cstdio>
#include<cstdlib>

#define BASE 1000000
#define DIGITS 10
#define MAXN 1005

using namespace std;

class bignum {
	public:
	int d[DIGITS];
	bignum() {
		for(int i = 0; i<DIGITS; i++) {
			d[i] = 0;
		}
	}
	bignum& operator+=(bignum other) {
		for(int i = 0; i<DIGITS; i++) {
			d[i] += other.d[i];
			if(i != DIGITS-1) d[i+1] += d[i]/BASE;
			d[i] %= BASE;
		}
		return *this;
	}
	bignum& operator-=(bignum other) {
		for(int i = 0; i<DIGITS; i++) {
			d[i] -= other.d[i];
			if(d[i] < 0) {
				d[i] += BASE;
				if(i != DIGITS-1) d[i+1]--;
			}
		}
		return *this;
	}
	bignum& operator<<=(int a) {
		while(a > 0) {
			for(int i = DIGITS-1; i>=0; i--) {
				d[i] *= 10;
				if(i != DIGITS-1) d[i+1] += d[i]/BASE;
				d[i] %= BASE;
			}
			a--;
		}
	}
	void write(FILE *fout) {
		bool started = false;
		for(int i = DIGITS-1; i>=0; i--) {
			if(d[i] != 0 || started) {
				if(!started) fprintf(fout,"%d",d[i]);
				else fprintf(fout,"%06d",d[i]);
				started = true;
			}
		}
		if(!started) {
			fprintf(fout,"0");
		}
	}
	bool operator<(bignum other) {
		for(int i = DIGITS-1; i>=0; i--) {
			if(d[i] < other.d[i]) return true;
			if(d[i] > other.d[i]) return false;
		}
		return false;
	}
	bignum& operator=(bignum other) {
		for(int i = 0; i<DIGITS; i++) {
			d[i] = other.d[i];
		}
	}
	bool zero() {
		for(int i = 0; i<DIGITS; i++) {
			if(d[i]) return false;
		}
		return true;
	}
	void div2() {
		for(int i = DIGITS-1; i>=0; i--) {
			if((d[i] & 1) && i) {
				d[i-1] += BASE;
				d[i]--;
			}
			d[i] /= 2;
		}
	}
	bool even() {
		return !(d[0]&1);
	}
	void clear() {
		for(int i = 0; i<DIGITS; i++) {
			d[i] = 0;
		}
	}
} t[MAXN];

bignum gcd(bignum a, bignum b) {
	int twocount = 0;
	if(a.zero() && b.zero()) return a;
	while(a.even() && b.even()) {
		twocount++;
		a.div2();
		b.div2();
	}
	while(!b.zero()) {
		while(a.even() && !a.zero()) a.div2();
		while(b.even() && !a.zero()) b.div2();
		if(a < b) {
			bignum temp;
			temp = a;
			a = b;
			b = temp;
		}
		a-=b;
	}
	for(int i = 0; i<twocount; i++) {
		a+=a;
	}
	return a;
}

int main() {
	FILE *fin = fopen("B.in","r"), *fout = fopen("B.out","w");
	int C;
	fscanf(fin,"%d",&C);
	for(int c = 1; c <= C; c++) {
		int N;
		bignum T;
		fscanf(fin,"%d ",&N);
		for(int i = 0; i<N; i++) {
			t[i].clear();
		}
		for(int i = 0; i<N; i++) {
			char ch;
			fscanf(fin,"%c",&ch);
			while(ch!=' ' && ch!='\n') {
				t[i]<<=1;
				t[i].d[0]+=ch-'0';
				fscanf(fin,"%c",&ch);
			}
//			printf("%d: ",i);
//			t[i].write(stdout);
//			printf("\n");
			for(int j = 0; j<i; j++) {
				if(t[j] < t[i]) {
					bignum temp;
					temp = t[i];
					temp -= t[j];
					T = gcd(T,temp);
				} else {
					bignum temp;
					temp = t[j];
					temp -= t[i];
					T = gcd(T,temp);
				}
			}
		}
		T.write(stdout);
		printf("\n");
		fflush(stdout);
		bignum y;
		int twocount = 0;
		while(!(t[0] < T)) {
			twocount++;
			T+=T;
		}
		if(twocount > 0) {
			twocount--;
			T.div2();
		}
		while(twocount >= 0) {
			y+=T;
			if(!(y < t[0])) {
				y-=T;
			}
			if(twocount > 0) {
				T.div2();
			}
			twocount--;
		}
		y+=T;
//		y.write(stdout);
//		printf("\n");
		y-=t[0];
		fprintf(fout,"Case #%d: ",c);
		y.write(fout);
		fprintf(fout,"\n");
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
