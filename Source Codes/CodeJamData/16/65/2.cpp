#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using D = double;
using ii = pair<int, int>;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

pair<D, D> calc(D y, D ys)
{
	D x = -10;
	D dx = 1.0 / 10000;
	D ans = 0;
	while (x < 10)
	{
// 		if (y > 100) return {1e100, 100};
// 		if (y < -100) return {1e100, -100};
		ans += (1 + 1.0 / (x * x + y * y)) * sqrt(1 + ys * ys) * dx;
		x += dx;
		D yss = (1 + ys * ys) * (2 * x * ys - 2 * y) / (x * x + y * y + 1) / (x * x + y * y);
// 		cout << x << ' ' << y << ' ' << ys << ' ' << yss << endl;
		y += ys * dx;
		ys += yss * dx;
	}
	return {ans, y};
}

int main()
{
	int NT;
	scanf("%d", &NT);
// 	NT = 1;
	for (int T = 1; T <= NT; T++)
	{
		printf("Case #%d:", T);
		
		int n;
		D a, b, pos;
		cin >> n >> a >> b;
		cin >> pos;
		a -= pos;
		b -= pos;
		D answer = 1e100;
		{
			D l = -3000.0 * abs(b - a) / 20.0;
			D r = -a / 10.0;
// 			cout << l << ' ' << r << endl;
			for (int IT = 0; IT < 100; IT++)
			{
				D m = (l + r) / 2;
				D t = calc(a, m).se;
// 				cout << "try " << a << ' ' << m << ' ' << t << endl;
				if (t < b) l = m;
				else r = m;
			}
			auto t = calc(a, l);
// 			cout << t.fi << ' ' << t.se << endl;
			answer = t.fi;
		}
		{
			D l = -a / 10.0;
			D r = 3000 * abs(b - a) / 20.0;
// 			cout << l << ' ' << r << endl;
			for (int IT = 0; IT < 100; IT++)
			{
				D m = (l + r) / 2;
				D t = calc(a, m).se;
// 				cout << "try " << a << ' ' << m << ' ' << t << endl;
				if (t < b) l = m;
				else r = m;
			}
			auto t = calc(a, l);
// 			cout << t.fi << ' ' << t.se << endl;
			answer = min(answer, t.fi);
		}
		
		printf(" %.7lf\n", answer);
		
		fprintf(stderr, "%d/%d tests completed!\n", T, NT);
	}

}
