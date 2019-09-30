#include <cstdio>
#include <algorithm>
#include <cstring>
#define f(x, y, z) for(int x = (y); x <= (z); ++x)
#define g(x, y, z) for(int x = (y); x < (z); ++x)
#define h(x, y, z) for(int x = (y); x >= (z); --x)

typedef long long LL;
struct num{
	char ch, neg;
};
num _mul[256][256], ONE, I, J, K, IJK;

inline num operator *(num x, num y){
	num tmp = _mul[x.ch][y.ch];
	if(x.neg != y.neg) tmp.neg = !tmp.neg;
	return tmp;
}
inline bool operator ==(num x, num y){
	return x.ch == y.ch && x.neg == y.neg;
}
inline bool operator !=(num x, num y){
	return x.ch != y.ch || x.neg != y.neg;
}

inline void num_init(){
	_mul['1']['1'] = (num) {'1', 0};
	_mul['1']['i'] = (num) {'i', 0};
	_mul['1']['j'] = (num) {'j', 0};
	_mul['1']['k'] = (num) {'k', 0};
	
	_mul['i']['1'] = (num) {'i', 0};
	_mul['i']['i'] = (num) {'1', 1};
	_mul['i']['j'] = (num) {'k', 0};
	_mul['i']['k'] = (num) {'j', 1};
	
	_mul['j']['1'] = (num) {'j', 0};
	_mul['j']['i'] = (num) {'k', 1};
	_mul['j']['j'] = (num) {'1', 1};
	_mul['j']['k'] = (num) {'i', 0};
	
	_mul['k']['1'] = (num) {'k', 0};
	_mul['k']['i'] = (num) {'j', 0};
	_mul['k']['j'] = (num) {'i', 1};
	_mul['k']['k'] = (num) {'1', 1};
	
	ONE = (num) {'1', 0};
	I = (num) {'i', 0};
	J = (num) {'j', 0};
	K = (num) {'k', 0};
	IJK = I * J * K;
}

inline void read(num &x){
	char c = getchar();
	while(c != 'i' && c != 'j' && c != 'k') c = getchar();
	x = (num) {c, 0};
}

inline num pow(num x, LL y){
	num ans = ONE;
	h(i, 60, 0){
		ans = ans * ans;
		if(y & (1LL << i)) ans = ans * x;
	}
	return ans;
}

int n; LL m;
num a[10007], prod[10007], succ[10007];

int main(){
	num_init();
	int T; scanf("%d", &T);
	f(_, 1, T){
		scanf("%d%I64d", &n, &m);
		prod[0] = ONE;
		f(i, 1, n){
			read(a[i]); prod[i] = prod[i - 1] * a[i];
		}
		num tmp = pow(prod[n], m);
		// printf("tmp %c %d\n", tmp.ch, tmp.neg);
		// printf("IJK %c %d\n", IJK.ch, IJK.neg);
		if(tmp != IJK){
			printf("Case #%d: NO\n", _);
			continue;
		}
		LL ans = 0x1f1f1f1f1f1f1f1fLL;
		LL a2 = ans;
		f(i, 1, n){
			LL up = m;
			if(up > 4) up = 4;
			g(j, 0, up){
				num c = pow(prod[n], j) * prod[i];
				if(c == I){
					LL ca = i + j * n;
					if(ca < ans) ans = ca;
				}
			}
		}
		succ[n + 1] = ONE;
		h(i, n, 1) succ[i] = a[i] * succ[i + 1];
		h(i, n, 1){
			LL up = m;
			if(up > 4) up = 4;
			g(j, 0, up){
				num c = succ[i] * pow(succ[1], j);
				if(c == K){
					LL ca = (n + 1 - i) + j * n;
					if(ca < a2) a2 = ca;
				}
			}
		}
		// printf("ans %I64d %I64d\n", ans, a2);
		LL tl = (LL) n * m;
		if(ans + a2 < tl) printf("Case #%d: YES\n", _);
		else printf("Case #%d: NO\n", _);
	}
	return 0;
}
