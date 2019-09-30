#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

char s1[105], s2[105];
long long cb[105][105];

void cal_cb() {
	cb[0][0] = 1;
	for (int i = 1; i <= 101; ++i) {
	  cb[i][0] = cb[i][i] = 1;
	  for (int j = 1; j < i && j <= 5; ++j) {
	    cb[i][j] = cb[i - 1][j] + cb[i - 1][j - 1];
		}
	}
}

class big {
public:	
	int l, num[115];
	
	big() {
	  l = 0;
	  num[1] = 0;
	  memset(num, 0, sizeof(num));
	}
	
	big(const int &a) {
		int tmp = a;
		while (tmp) {
			num[++l] = tmp % 10;
		  tmp = tmp / 10;
		}
	}
	
	big(char *s) {
	  l = strlen(s);
	  for (int i = 1; i <= l; ++i) {
	    num[i] = s[l - i] - '0';
		}
	}
	
	void print() {
	  for (int i = l; i >= 1; -- i) {
	    printf("%d", num[i]);
		}
		printf("\n");
	}
}a, b, c;

bool operator <= (const big &a, const big &b) {
  if (a.l != b.l) return a.l < b.l;
  for (int i = a.l; i > 0; --i) {
    if (a.num[i] != b.num[i]) return a.num[i] < b.num[i];
	}
  return true;
}

big operator - (const big &a, const int b) {
	big ret = a;
	ret.num[1] -= b;
	int i = 1;
	while (ret.num[i] < 0) {
	  ret.num[i] += 10;
	  ret.num[i + 1] -= 1;
	  ++i;
	}
	if (i == ret.l && ret.num[i] == 0) --ret.l;
	if (ret.l == 0) ret.l = 1;
	return ret;
}

big operator * (const big &a, const big &b) {
	big c;
	for (int i = 1; i <= a.l; ++i) {
		if (a.num[i] == 0) continue;
	  for (int j = 1; j <= b.l; ++j) {
	    c.num[i + j - 1] += a.num[i] * b.num[j];
		}
	}
	for (int i = 1; i <= a.l + b.l - 1; ++i) {
		c.num[i + 1] += c.num[i] / 10;
		c.num[i] %= 10;
	}
	c.l = a.l + b.l - 1;
	if (c.num[c.l + 1] != 0) ++c.l;
	return c;
}

big res(const int i, const int l) {
  big ret;
  ret.l = l; ret.num[1] = ret.num[l] = i;
  return ret;
}

long long cal2(big base, int m, big p) {
	//printf("Cal2\n"); base.print(); printf("%d\n", m); p.print();
	if (m == 0) return (base * base <= p ? 1ll : 0ll);
	big tmp;
	long long ret = 0;
	int l = base.l, cnt;
	for (int i = 1; i <= m; ++i) {
		tmp = base;
		cnt = i;
		for (int j = 1; l - j + 1 > j; ++j) {
		  tmp.num[j] = tmp.num[l - j + 1] = 1;
		  if (tmp * tmp <= p) {
		  	if (j != 1) ret = ret + cb[l / 2 - j][cnt];
		  	--cnt;
		  	if (cnt == 0) {
		  	  ++ret;
		  	  break;
				}
		  } else {
		    tmp.num[j] = tmp.num[l - j + 1] = 0;
		    if (j == 1) break;
			}
		}
	}
	return ret;
}

long long cal(big p) {
	//printf("Cal"); p.print();
	long long ans = 0;
	if (p.l > 1 || p.l == 1 && p.num[1] >= 9) ans = 1;
	big tmp;
	for (int l = 1; l <= p.l; ++l) {
		tmp = res(1, l);
		//cout << l << ' ' << "tmp "; tmp.print();
		if (!(tmp * tmp <= p)) break;
		if (l % 2 == 1) {
	    //2 in middle
	    tmp.num[l / 2 + 1] = 2;
	    ans += cal2(tmp, min(2, l / 2), p);
	    //1 in middle
			if (l != 1) {
				tmp = res(2, l);	    
			  tmp.num[l / 2 + 1] = 1;
			  if (tmp * tmp <= p) ++ans;
			}

      tmp.num[l / 2 + 1] = 1;
			ans += cal2(tmp, min(4, l / 2), p);
		}
		if (l == 1) continue;
		//non middle
		//2000...0002
		tmp = res(2, l);
		if (tmp * tmp <= p) ++ans;
		//1000...0001
		tmp = res(1, l);
		ans += cal2(tmp, min(4, l / 2), p);
	}
	return ans;
}

int main() {
	
	freopen("C.in", "r", stdin);
	freopen("C3.out", "w", stdout);
	
	cal_cb();
	int T;
	long long ans;
	scanf("%d", &T);
	for (int V = 1; V <= T; ++V) {  
	  scanf("%s%s", s1, s2);
	  a = big(s1) - 1;
		b = big(s2);
	  ans = cal(b) - cal(a);
	  //cout << cal(b) << ' ' << cal(a) << endl;
	  printf("Case #%d: %I64d\n", V, ans);
	}	
	return 0;
}

