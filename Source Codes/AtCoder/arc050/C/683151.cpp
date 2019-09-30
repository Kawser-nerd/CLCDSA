#include <iostream>
#include <cstring>
using namespace std;

typedef long long intl;
intl mod;

struct Matrix
{
	int n, m;
	intl num[2][2];
	Matrix() { }
	Matrix(int n, int m) : n(n), m(m)
	{
		memset(num, 0, sizeof(num));
	}
	Matrix operator *(const Matrix rhs) const
	{
		Matrix ret(n, rhs.m);
		for(int i = 0; i < n; i ++)
			for(int j = 0; j < rhs.m; j ++)
				for(int k = 0; k < m; k ++)
				{
					ret.num[i][j] += num[i][k] * rhs.num[k][j];
					ret.num[i][j] %= mod;
				}
		return ret;
	}
};

intl qpow(intl a, intl b)
{
	intl tmp = a;
	intl ret = 1;
	while(b > 0)
	{
		if(b & 1)
		{
			ret *= tmp;
			ret %= mod;
		}
		tmp *= tmp;
		tmp %= mod;
		b >>= 1;
	}
	return ret;
}

Matrix qpow(Matrix a, intl b)
{
	Matrix ret(2, 2);
	Matrix tmp = a;
	ret.num[0][0] = ret.num[1][1] = 1;
	while(b > 0)
	{
		if(b & 1)
			ret = ret * tmp;
		tmp = tmp * tmp;
		b >>= 1;
	}
	return ret;
}

intl gcd(intl a, intl b)
{
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
	ios :: sync_with_stdio(false);
	intl a, b;
	cin >> a >> b >> mod;
	intl g = gcd(a, b);
	intl bb = qpow(10, g);

	Matrix sta(2, 2);
	sta.num[0][0] = 10;
	sta.num[0][1] = sta.num[1][1] = 1;
	Matrix ra(2, 1);
	ra.num[0][0] = 0;
	ra.num[1][0] = 1;
	ra = qpow(sta, a) * ra;

	Matrix stb(2, 2);
	stb.num[0][0] = bb;
	stb.num[0][1] = stb.num[1][1] = 1;
	Matrix rb(2, 1);
	rb.num[0][0] = 0;
	rb.num[1][0] = 1;
	rb = qpow(stb, b / g) * rb;

	cout << ra.num[0][0] * rb.num[0][0] % mod << '\n';
	return 0;
}