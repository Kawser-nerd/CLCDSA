#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

//UPC BIGINT
using namespace std;
typedef vector<int> VE;
typedef long long ll;
const ll base = 1000000000; // 9 zeros
class BI { public:
VE v; // el digit menys significatiu es v[0]
int n; // v.size()
int sig; // 1: positiu o zero, -1: negatiu
// GENERAL PER A TOT
void zero() { v = VE(1, 0); n = sig = 1; }
void remida(int i, int que=0) { v.resize(n = i, que); }
void treuzeros(){
while (--n and !v[n]);
remida(n+1);
if (n == 1 and !v[0]) sig = 1;
}
void parse(string num) {
if (num[0] == '-') { sig = -1; num = num.substr(1); }
else sig = 1;
int m = num.size() - 1;
v = VE(1 + m/9, 0); n = v.size();
for (int i = m, exp = 0, pw = 1, pos = 0; i >= 0; --i, ++exp, pw *= 10) {
if (exp == 9) { exp = 0; pw = 1; ++pos; }
v[pos] += (num[i] - '0')*pw;
}
treuzeros();
}
// DESIGUALTATS
// compara en valor absolut, 0: == b, positiu: > b; negatiu: < b
inline int compabs(const BI &b) const {
if (n != b.n) return n - b.n;
for (int i = n - 1; i >= 0; --i)
if (v[i] != b.v[i]) return v[i] - b.v[i];
return 0;
}
// 0: == b, positiu: > b; negatiu: < b
inline int compara(const BI &b) const {
if (sig != b.sig) return sig - b.sig;
return sig*compabs(b);
}
inline bool operator==(const BI &b) const { return !compara(b); }
inline bool operator!=(const BI &b) const { return compara(b); }
inline bool operator<(const BI &b) const { return compara(b) < 0; }
inline bool operator<=(const BI &b) const { return compara(b) <= 0; }
inline bool operator>(const BI &b) const { return compara(b) > 0; }
inline bool operator>=(const BI &b) const { return compara(b) >= 0; }
// |x| < 10^9
inline bool operator==(int x) { return n == 1 and sig*v[0] == x; }
// OPERACIONS EN VALOR ABSOLUT
inline int dig(int i) { return (i < n ? v[i] : 0); }
void suma(BI &b) {
if (n < b.n) remida(b.n, 0);
int ca = 0;
for (int i = 0; i < n; ++i) {
v[i] += b.dig(i) + ca; ca = v[i]/base; v[i] %= base;
}
if (ca) remida(n+1, ca);
}
// suposa >= b
void resta(BI &b) {
int ca = 0;
for (int i = 0; i < n; ++i) {
v[i] += base - b.dig(i) + ca; ca = v[i]/base - 1; v[i] %= base;
}
treuzeros();
}
// INICIALITZACIONS I COPIA
BI() { zero(); }
BI(const BI &b) { *this = b; }
// |x| < 10^18
BI(ll x) {
sig = (x < 0 ? -1 : 1); x *= sig;
if (x < base) { v = VE(1, x); n = 1; }
else { v = VE(2); v[0] = x % base; v[1] = x/base; n = 2; }
}
BI(string num) { parse(num); }
void operator=(const BI &b) { v = b.v; n = b.n; sig = b.sig; }
// OPERACIONS
void operator+=(BI &b) {
if (sig == b.sig) return suma(b);
if (compabs(b) >= 0) return resta(b);
BI aux(b); aux.resta(*this); *this = aux;
}
void operator-=(BI &b) {
if (&b == this) return zero();
b.sig *= -1; operator+=(b); b.sig *= -1;
}
// |x| < 10^9
void operator*=(int x) {
if (x < 0) { sig *= -1; x *= -1; }
remida(n + 1, 0);
ll ca = 0;
for (int i = 0; i < n; ++i) {
ca += (ll)v[i]*x; v[i] = ca % base; ca /= base;
}
treuzeros();
}
void operator*=(BI &b) {
BI c; c.remida(n + b.n, 0); c.sig = sig*b.sig;
for (int i = 0; i < n; ++i)
for (int j = 0; j < b.n; ++j) {
int k = i + j;
ll z = (ll)v[i]*b.v[j] + c.v[k], y;
while ((y = z / base)) { c.v[k] = z % base; z = y + c.v[++k]; }
c.v[k] = z;
}
c.treuzeros();
*this = c;
}
// |x| < 10^9
void operator/=(int x) {
if (x < 0) { sig *= -1; x *= -1; }
ll ca = 0;
for (int i = n-1; i >= 0; --i ) {
ca += v[i]; v[i] = ca/x; ca %= x; ca *= base;
}
treuzeros();
}
void operator/=(BI &b){
if (compabs(b)<0) return zero();
if (b.n==1) *this/=b.sig*b.v[0];
else {
int st = sig*b.sig, sb = b.sig; sig = b.sig = 1;
vector<BI> VB,pot2;
VB.push_back(b); pot2.push_back(1);
BI curr=0;
//primera pasada
while (VB[VB.size()-1]<=*this){
BI ultimo=VB[VB.size()-1]; ultimo+=ultimo; VB.push_back(ultimo);
ultimo=pot2[pot2.size()-1]; ultimo+=ultimo; pot2.push_back(ultimo);
}
curr+=pot2[pot2.size()-2]; (*this)-=VB[VB.size()-2];
//resto
while ((*this)>=b){
int i=0;
while (VB[i]<=(*this)) i++;
curr+=pot2[i-1]; (*this)-=VB[i-1];
}
(*this)=curr; sig = st; b.sig = sb;
}
}
// |x| < 10^9; amb negatius funciona com C++
ll mod(int x) {
if (x < 0) x *= -1;
ll ca = 0;
for (int i = n-1; i >= 0; --i ) { ca *= base; ca += v[i]; ca %= x; }
return ca;
}
void operator%=(BI &b) {
BI r(*this); r /= b; r*= b; operator-=(r);
}
void mcdrec(BI &b, BI &c) {
if (c == 0) return *this = b;
b %= c; mcdrec(c, b);
}
void mcd(BI &b, BI& c) { BI bb(b), cc(c); mcdrec(bb, cc); }
void powrec(BI &aux, ll p) {
if (!p) return;
powrec(aux, p/2);
aux *= aux;
if (p % 2) aux *= (*this);
}
void pow(ll p) { BI aux(1); powrec(aux, p); *this = aux; }
int log(int x) {
BI a(*this);
int n1=(a.v.size()-1)*9+(int)log10((double)a.v[v.size()-1]);
//n1 es nuestra aproximacion en base 10, es decir 10^{n1} <= N < 10^{n1+1}
//la aproximacion es exacta, ahora busquemos una aproximacion "aproximada"
int arriba,abajo;
abajo=(int)((double)(n1)/(log10((double)x)));
arriba=(int)((double)(n1+1)/(log10((double)x)))+1;
BI b=x; b.pow((ll)abajo);
BI c=b; c*=x;
while (1){
if (c>a){return abajo; }
b=c;
c*=x; abajo++;
}
}
void raizcu(){ //raiz cuadrada
if (*this==0) return;
vector<BI> divi;
BI tab[10]={(0),(1),(4),(9),(16),(25),(36),(49),(64),(81)};
BI nueve(9),uno(1);
divi.push_back(*this);
while (*this>=100){
*this/=100; divi.push_back(*this);
}
BI res(0),cuad;
for (int i=1;i<10;i++){
if (tab[i]>divi[divi.size()-1].v[0]){ res=i-1; cuad=tab[i-1]; break;}
}
if (res==0){ res=nueve; cuad=81; }
for (int i=divi.size()-2;i>=0;i--){
BI cienequiscu,veintecequis,c(0); bool b=false;
cienequiscu=cuad; cienequiscu*=100; veintecequis=res; veintecequis*=20; cuad*=100;
for (int j=1;j<10;j++){
cienequiscu+=veintecequis; cienequiscu+=tab[j];
if (cienequiscu>divi[i]){b=true; res*=10; res+=c; break;}
cuad=cienequiscu; cienequiscu-=tab[j]; c+=uno;
}
if (!b){ res*=10; res+=nueve; }
}
*this=res;
}
void arrel(int x) { //raiz n-esima: lenta
if (*this == 0) return;
BI dre(1), q(1);
do { dre += dre; for (int r = 0; r < x; ++r) q += q; } while (q <= *this);
BI aux, esq(dre); esq /= 2;
while (aux = dre, aux -= esq, aux != 1) {
BI m(esq); m += dre; m /= 2;
q = m; q.pow(x);
if (q > *this) dre = m; else esq = m;
}
*this = esq;
}
friend ostream &operator<<(ostream &out, BI &b) {
if (b.sig < 0) out << '-';
int i = b.v.size() - 1;
out << b.v[i];
for (--i; i >= 0; --i) out << setw(9) << setfill('0') << b.v[i];
return out;
}
friend istream &operator >>(istream &in, BI &b) {
string num; in >> num; b.parse(num);
return in;
}
};

int main() {
    int casos;
    cin >> casos;
    for (int z = 1; z<= casos; ++z) {
        cout << "Case #" << z << ": ";
        int n;
        cin >> n;
        vector<BI> v(n);
        BI cero = 0;
        BI res = 0;
        for (int i = 0; i < n; ++i) cin >> v[i];
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                BI c, d = v[i];
                d -= v[j];
                if (d < cero) d*=-1;
                c.mcd(res, d);
                res = c;
            }
        }
        BI a = v[0];
        a%=res;
        if (a == 0) cout << 0 << endl;
        else {
            res -= a;
            cout << res << endl;
        }
    }
}

        
