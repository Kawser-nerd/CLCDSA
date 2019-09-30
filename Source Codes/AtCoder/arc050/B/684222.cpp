#include <iostream>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/lu.hpp>
#define repeat(i,n) for (int i = 0; (i) < (n); ++(i))
#define repeat_from(i,m,n) for (int i = (m); (i) < (n); ++(i))
typedef long long ll;
using namespace std;
template <class T> bool setmax(T & l, T const & r) { if (not (l < r)) return false; l = r; return true; }
namespace ublas = boost::numeric::ublas;
typedef ublas::vector<long double> vec;
typedef ublas::matrix<long double> mat;
int main() {
    ll b1, b2, a11, a22; cin >> b1 >> b2 >> a11 >> a22;
    ll ans = 0;
    repeat (i,3) {
        ll c1, c2;
        if (i == 0) {
            mat a(2,2); vec b(2);
            a(0,0) = a11; a(0,1) =   1;    b[0] = b1;
            a(1,0) =   1; a(1,1) = a22;    b[1] = b2;
            ublas::permutation_matrix<> pm(a.size1());
            ublas::lu_factorize(a,pm); // throws if singular
            ublas::lu_substitute(a,pm,b);
            c1 = b[0];
            c2 = b[1];
        } else if (i == 1) {
            c1 = 0;
            c2 = min(b1, b2 / a22);
        } else if (i == 2) {
            c1 = min(b2, b1 / a11);
            c2 = 0;
        }
        repeat_from (dx,-100,100+1) {
            ll x = c1 + dx;
            if (x < 0) continue;
            repeat_from (dy,-100,100+1) {
                ll y = c2 + dy;
                if (y < 0) continue;
                if (a11 * x + y <= b1 and x + a22 * y <= b2) {
                    setmax(ans, x + y);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}