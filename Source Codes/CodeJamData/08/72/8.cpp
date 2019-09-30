#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <vector>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <bitset>
#include <cassert>
using namespace std;

#define FOR(a,b,c) for(int a=(int)(b);a<(int)(c);a++)
#define ITER(a,b) for(__typeof((b).begin()) a = (b).begin(); a!=(b).end(); a++)
#define MEMSET(dest,val) memset(dest,val,sizeof(dest))
#define PAIR pair<int,int>
#define BEGEND(a) (a).begin(), (a).end()
#define SHIFT(v) (1LL<<(v))
#define SQ(a) ((a) * (a))
#define LSB(a,b) (b<=sizeof(a)?(b & (SHIFT(a)-1)):LLMAX)

#define eps 1E-9
#define PI acos(-1.0)
#define INF 1000000000
#define LINF 90000000000000000000LL
#define LLMAX ((unsigned long long)(-1))

//BEGIN CUT - BitStuff
int numBits(unsigned long long v) {return __builtin_popcount(v>>32) + __builtin_popcount(v & ((SHIFT(32)-1)));}
int highestBit(unsigned long long v) { return (v==0)?-1:(((v>>32)!=0)?63-__builtin_clz(v>>32):31-__builtin_clz(v));}
int lowestBit(unsigned long long v) { return (v==0)?-1:((((v>>32)<<32)==v)?32 + __builtin_ctz(v>>32):__builtin_ctz(v));}
inline void flip(long long &m, int v) { m ^= SHIFT(v);}
inline void flip(int &m, int v) { assert(v<32); m ^= SHIFT(v);}
bitset<8> toBinary(char c) { return bitset<8>(c);}
bitset<32> toBinary(int n) { return bitset<32>(n);}
bitset<64> toBinary(long long n){ return bitset<64>(bitset<64>(n) | (bitset<64>(n>>32)<<32));}
//END CUT - BitStuff

//BEGIN CUT - HexStuff
string _hexdigits = "0123456789ABCDEF";
unsigned long long toHexLong(string str){ unsigned long long num = 0; FOR(i,0,str.length()) { num<<=4; if(isalpha(str[i])) num += (str[i]-'A'+10); else num += (str[i]-'0');} return num; }
string toHexString(unsigned long long num) {string ret; FOR(k,0,16) { ret += _hexdigits[((num>>(k<<2))&0xF)]; } reverse(ret.begin(),ret.end()); return ret;}
//END CUT - HexStuff

//BEGIN CUT - Math Functions - O(digits^2)
long long gcd(long long A, long long B){  if(!A && !B) return 0;  return (A%B)?gcd(B,A%B):B; }
long long lcm(long long A, long long B){ if(!A && !B) return 0; return A / gcd(A,B) * B; }
//END CUT - Math Functions

//BEGIN CUT - Random Functions
static bool _seeded = false;
unsigned long long lrand(int seed=-1){ if(!_seeded) _seeded=true,srand((seed==-1)?time(0):seed); return ((((unsigned long long)rand())<<32) | rand());}
//END CUT - Random Functions

//BEGIN CUT - fraction structure
struct frac{
public:   frac(long long A=0, long long B=1):num(A), denom(B){} frac operator=(const frac &rhs) { this->num = rhs.num; this->denom = rhs.denom; return reduce();}
   frac operator*(const frac & rhs){ if(num==0||rhs.num==0) return frac(); long long g1=gcd(abs(num),rhs.denom), g2=gcd(denom,abs(rhs.num)); return frac((num/g1)*(rhs.num/g2),(denom/g2)*(rhs.denom/g1));} frac operator*=(const frac &rhs){return (*this)=operator*(rhs);}
   frac operator+(const frac &rhs){long long _lcm = lcm(denom,rhs.denom); return frac(num*(_lcm/denom) + rhs.num*(_lcm/rhs.denom),_lcm).reduce();} frac operator+=(const frac &rhs){return (*this)=operator+(rhs);}
   frac operator-(const frac &rhs){ return (*this)+frac(-rhs.num,rhs.denom);} frac operator-=(const frac &rhs){return (*this)=operator-(rhs);}
   frac operator/(const frac &rhs){ assert(rhs.num!=0); return (*this)*frac(rhs.denom,rhs.num);} frac operator/=(const frac &rhs){return (*this)=operator/(rhs);}
   bool operator==(frac rhs){ rhs.reduce(); return num==rhs.num && denom==rhs.denom;} bool operator!=(const frac & rhs) { return !((*this)==rhs);}
   bool operator<(const frac &rhs){ long long _lcm = lcm(denom,rhs.denom); return num * (_lcm/denom) < rhs.num * (_lcm/rhs.denom);} bool operator<=(const frac &rhs) { return (*this)==rhs || (*this) < rhs;}
   bool operator>(const frac &rhs){ return !((*this) <= rhs);} bool operator>=(const frac &rhs){ return !((*this)<rhs);}
   frac reduce() { long long g = gcd(num,denom); if(g>1){num/=g,denom/=g;} return (*this);} string toString(){stringstream ss; ss << num << "/" << denom; return ss.str();}
private:    long long num, denom;
};
//END CUT - fraction structure


//BEGIN CUT - bigint structure
struct bigint{
private:
   int size; bool negative; long long *data;   // in reverse order

   int abscmp(const bigint &rhs) const{ int mn = min(rhs.size,size); for(int j=size-1;j>=mn;j--) if(data[j]!=0) return 1; for(int j=rhs.size-1;j>=mn;j--) if(rhs.data[j]!=0) return -1; for(int j=mn-1;j>=0;j--) if(data[j]!=rhs.data[j]) return ((unsigned long long)(data[j])>(unsigned long long)(rhs.data[j]))?1:-1; return 0;}
   bigint add(const bigint &rhs){ bigint mx = (rhs.size>=size)?rhs:(*this), mn = (rhs.size>=size)?(*this):rhs; int c = 0; FOR(i,0,mn.size) { mx.data[i] += mn.data[i] + c; c = (mx.data[i]>=0 && (rhs.data[i]<0||data[i]<0)) ? 1 : 0;} FOR(i,mn.size,mx.size){ mx.data[i] += c; c = (c==1&&mx.data[i]==0)?1:0;} if(c) { bigint nx(0,mx.size+1); memcpy(nx.data,mx.data,sizeof(mx.data)*mx.size); nx.data[nx.size-1] = 1; return nx;} return mx;}
   bigint sub(const bigint &rhs){ int borrow = 0; bigint ret = (*this); ret.negative = false; int end = rhs.size-1; while(end > 0 && data[end]==0) end--; FOR(i,0,end+1){ unsigned long long A = ret.data[i]-borrow, B = rhs.data[i]; int nborrow = (borrow && ret.data[i]==0)?1:0; if(A >= B) ret.data[i] = A-B; else nborrow = 1, ret.data[i] = 0-B+A; borrow = nborrow;} return ret;}

public:
   bigint(long long val=0, int sz=1) {data = new long long[size = sz]; memset(data,0,sizeof(data)*size); data[0] = abs(val); negative = (val<0);}
   bigint(const bigint &rhs) { data = new long long[size = rhs.size]; memcpy(data,rhs.data,sizeof(data)*size); negative = rhs.negative;}
   bigint(string str){ negative = false; if(str[0] == '-') negative = true, str = str.substr(1); bool zero = true; assert((str.length()+1)%17==0); size = (str.length()+1)/17; data = new long long[size]; FOR(i,0,size) { data[size-i-1] = toHexLong(str.substr(i*17,16)); zero = zero && data[size-i-1]==0;} if(zero) negative = false;}
   bigint operator=(const bigint &rhs){ size = max(size,rhs.size); delete [] data; data = new long long[size]; negative = rhs.negative; memset(data,0,sizeof(data)*size); memcpy(data,rhs.data,sizeof(rhs.data)*rhs.size); return (*this);}
   ~bigint() { delete [] data; data = NULL;}

   int cmp(const bigint &rhs) const{ if(negative != rhs.negative) return negative?-1:1; else return abscmp(rhs) * (negative?-1:1); }
   bool operator==(const bigint &rhs) const { return cmp(rhs)==0;}
   bool operator!=(const bigint &rhs) const { return cmp(rhs)!=0;}
   bool operator< (const bigint &rhs) const { return cmp(rhs)==-1;}
   bool operator>=(const bigint &rhs) const { return cmp(rhs)!=-1;}
   bool operator<=(const bigint &rhs) const { return cmp(rhs)!=1;}
   bool operator> (const bigint &rhs) const { return cmp(rhs)==1;}

   bigint operator-() const{ bigint ret = (*this); if(ret!=0) ret.negative = !negative; return ret; }

   bigint operator<<=(int num) { return (*this) = ((*this)<<num); }
   bigint operator>>=(int num) { return (*this) = ((*this)>>num); }

   bigint operator+=(const bigint &rhs){ return (*this) = (*this) + rhs;}
   bigint operator*=(const bigint &rhs){ return (*this) = (*this) * rhs;}
   bigint operator-=(const bigint &rhs){ return (*this) = (*this) - rhs;}
   bigint operator/=(const bigint &rhs){ return (*this) = (*this) / rhs;}
   bigint operator%=(const bigint &rhs){ return (*this) = (*this) % rhs;}

   bigint operator<<(int num){ 
      int added = num/64; num = num % 64; // FINISH THIS
      bigint ret(0,size+added+1); int dest = added, mask = 0; for(int src = 0; src<size; src++, dest++){ ret.data[dest] = (data[src]<<num) + mask; mask = data[src] - LSB(64-num,data[src]); }
      ret.data[dest] = mask; return ret;
   }

   bigint operator>>(int num){
      int removed = num/64; num = num % 64; // FINISH THIS
      bigint ret(0,max(1,size - removed)); int dest = ret.size-1; unsigned long long mask = 0;
      for(int src = size-1; src>=0&&dest>=0; src--, dest--){ ret.data[dest] = LSB(64-num,(data[src]>>num)) | (mask<<(64-num)); mask = LSB(num,data[src]);}
      return ret;
   }

   bigint operator+(const bigint &rhs){ if(negative!=rhs.negative) switch(abscmp(rhs)){ case 0: return 0; case 1: return (abs(*this) - abs(rhs)) * (negative?-1:1); case -1: return (abs(rhs) - abs(*this)) * (rhs.negative?-1:1);} bigint ret = add(rhs); ret.negative = negative; return ret;}
   bigint operator-(const bigint &rhs){ if(negative != rhs.negative) return (abs(*this) + abs(rhs)) * (negative?-1:1); switch(abscmp(rhs)){ case 0: return 0; case 1: return abs(*this).sub(abs(rhs)) * (negative?-1:1); case -1: return abs(rhs).sub(abs(*this)) * (negative?1:-1);} return 0; }
   bigint operator*(const bigint &rhs){ int sz = max(size,rhs.size); long long *tempA = new long long[2*sz], *tempB = new long long[2*sz], *tempC =  new long long[4*sz]; memset(tempA,0,sizeof(tempA)*2*sz); memset(tempB,0,sizeof(tempB)*2*sz); memset(tempC,0,sizeof(tempC)*4*sz); FOR(i,0,size) tempA[i*2] = LSB(32,data[i]), tempA[i*2+1]=LSB(32,(data[i]>>32)); FOR(i,0,rhs.size) tempB[i*2] = LSB(32,rhs.data[i]), tempB[i*2+1]=LSB(32,(rhs.data[i]>>32)); for(int d=0;d<sz*4-1;d++) for(int i=max(d-sz*2+1,0);i<sz*2;i++){ int j = d-i; if(j >= 2*sz || j < 0) continue; long long res = tempA[i]*tempB[j]; tempC[i+j] += LSB(32,res), tempC[i+j+1] += LSB(32,(res>>32));} long long carry = 0; FOR(i,0,sz*4){ tempC[i] += carry; carry = LSB(32,(tempC[i]>>32)); tempC[i] = LSB(32,tempC[i]);} int j; for(j=sz*4-1;j>0&&tempC[j]==0;j--); bigint ret(0,(j/2)+1); FOR(i,0,ret.size) ret.data[i] = tempC[i*2] + (tempC[i*2+1]<<32); delete [] tempA; delete [] tempB; delete [] tempC; ret.negative = (negative!=rhs.negative); return ret;}
   bigint operator/(const bigint &rhs){ bigint d, r; abs(*this).div(abs(rhs),d,r); if(negative!=rhs.negative && d!=0) d.negative = true; return d;}
   bigint operator%(const bigint &rhs){ bigint d, r; abs(*this).div(abs(rhs),d,r); return r;}

   void div(const bigint &rhs, bigint &D, bigint &R){
            assert(rhs!=0); D = R = 0;	// IMPROVE THIS
            switch(abscmp(rhs)){ case -1: R = (*this); break; case 0: D = 1; break; case 1: { bigint low = 0, high = (*this);
                    while(true){ bigint k = (high-low+1); bigint k2 = low + (k>>1); D = low + ((high - low + 1)>>1); bigint mult = D*rhs; R = (*this)-(D*rhs); if(R < 0) high = D; else if(R >= rhs) low = D; else return;}}}
   }

   static bigint rand(const bigint &upperInc){ 
          assert(upperInc>=0); int s, k; bool onBounds = true; for(s=upperInc.size-1;s>0&&upperInc.data[s]==0;s--); for(k=63;k>0;k--) if(SHIFT(k) & upperInc.data[s]) break;  k++; 
          unsigned long long first = LSB(k,LLMAX); bigint ret(0,upperInc.size); for(int j=s;j>=0;j--){ unsigned long long lr = lrand(); 
              if(j==s){ lr&=first; if(lr > upperInc.data[j]){ j = s+1; onBounds = true; continue; } ret.data[j] = lr; if(lr < upperInc.data[j]) onBounds = false;
              } else if(onBounds){ if(lr > upperInc.data[j]) { j = s+1; onBounds = true; continue;} ret.data[j] = lr; if(lr < upperInc.data[j]) onBounds = false;
               } else ret.data[j] = lr;
        } 
 return ret;
}
   long long getLSB() const { assert(data); return data[0];}
   bool isNegative() const { return negative;}
   string toString() const{ int j; string ret; for(j=size-1;j>0&&(data[j]==0);j--); for(;j>=0;j--) ret += ":" + toHexString(data[j]); ret = ret.substr(1); if(negative) ret = "-" + ret; return ret;}
   friend bigint abs(const bigint &rhs);
};

ostream &operator<<(ostream &out, const bigint & rhs){ return out << rhs.toString();}
bigint abs(const bigint &rhs) { bigint ret = rhs; ret.negative = false; return ret;}
bigint bigint_choose(long long T, long long B){ bigint ret = 1; vector<long long> top, bottom; if(T<B || B<0) return -1; B = min(B,T-B); FOR(i,0,B){ top.push_back(T-i); bottom.push_back(i+1); } FOR(i,0,top.size()) FOR(j,0,bottom.size()){ if(top[i]==1) break; long long g = gcd(top[i],bottom[j]); top[i]/=g; bottom[j]/=g; if(bottom[j]==1){ swap(bottom[bottom.size()-1],bottom[j--]); bottom.pop_back();} } FOR(i,0,top.size()) ret*=top[i]; return ret;}
bigint bigint_factorial(long long T){ T = abs(T); bigint ret(T); FOR(i,2,T) ret *= i; return ret;}
//END CUT - BigINT


//BEGIN CUT - Print Array - O(N)
template<class T> 
void printArray(const vector<T> & v) { FOR(i,0,v.size()) cout << v[i] << " "; cout << endl; }
template <class T>
void printArray(const vector<vector<T> > &v){ FOR(i,0,v.size()) printArray(v[i]);}
//END CUT - Print Array

//BEGIN CUT - Set FUNCTIONS O(N)
template<class T>
void setIntersect(const set<T> &A, const set<T> &B, set<T> &C){ set_intersection(A.begin(),A.end(),B.begin(),B.end(),inserter(C,C.begin())); }
template<class T>
void setDifference(const set<T> &A, const set<T> &B, set<T> &C){ set_difference(A.begin(),A.end(),B.begin(),B.end(),inserter(C,C.begin()));}
//END CUT - Set FUNCTIONS

//BEGIN CUT - Disjoint Set Forest - O(m*a(n))		NOTE: First Convert to indeces on the range (0.._MAX_DJSFSIZE]
#define _MAX_DJSFSIZE 1
int _djsParent[_MAX_DJSFSIZE], _djsRank[_MAX_DJSFSIZE];
void djs_init(){ MEMSET(_djsParent,-1); MEMSET(_djsRank,-1);}
bool djs_makeset(int pos){ if(pos < 0 || pos>=_MAX_DJSFSIZE || _djsParent[pos]!=-1) return false;_djsParent[pos]=pos; _djsRank[pos]=0; return true;}
int djs_findset(int pos){ if(_djsParent[pos]!=pos){ _djsParent[pos] = djs_findset(_djsParent[pos]);} return _djsParent[pos];}
bool djs_union(int posA, int posB){ int pA = djs_findset(posA), pB = djs_findset(posB); if(pA==pB) return false; if(_djsRank[pA]>_djsRank[pB]) _djsParent[pB] = pA; else if(_djsRank[pB]>_djsRank[pA]) _djsParent[pA]=pB; else _djsParent[pA]=pB, _djsRank[pA]++; return true;}
//END CUT - Disjoing Set Forest

//BEGIN CUT - Binary Indexed Tree - O(log(V))
#define _BIT_SIZE 1
long long _BIT_freq[_BIT_SIZE];
void bit_init(){ MEMSET(_BIT_freq,0);}
long long bit_getCumulative(int pos){ pos++; assert(pos>=0 && pos<_BIT_SIZE); long long ret = 0; while(pos>0){ ret += _BIT_freq[pos]; pos -= (pos & -pos);}return ret;}
long long bit_getSingular(int pos){ pos++; assert(pos>=0 && pos<_BIT_SIZE); long long ret = _BIT_freq[pos]; if(pos > 0){ int z = pos - (pos & -pos); pos--; while(pos!=z){ ret -= _BIT_freq[pos]; pos -= (pos & -pos);}}return ret;}
bool bit_update(int pos, long long delta){ pos++; if(pos<1 || pos>=_BIT_SIZE) return false; while(pos < _BIT_SIZE){ _BIT_freq[pos] += delta; pos += (pos&-pos);}return true;}
        /* find smallest x such that c[x] >= cumFre */
long long bit_find(int cumFre){ long long pos = 0, bitMask=0; FOR(i,0,64) if(SHIFT(i)>=_BIT_SIZE) break; else if(SHIFT(i) & (_BIT_SIZE-1)) bitMask = SHIFT(i); int ret = _BIT_SIZE;while ((bitMask != 0) && (pos < _BIT_SIZE)){  int mid = pos + bitMask; if(mid < _BIT_SIZE){  if (cumFre > _BIT_freq[mid]){ pos = mid; cumFre -= _BIT_freq[mid];}  else ret = min(ret,mid);} bitMask >>= 1;}if(ret == _BIT_SIZE) return -1;return ret-1;}
// BEGIN CUT - Concatenate - O(N)
string concatenate(vector<string> &str){ string s; FOR(i,0,str.size()) s += str[i]; return s;}
// END CUT - Concatenate

// BEGIN CUT - Sieve of Eratosthenes
#define _SE_SIZE 1LL
bitset<_SE_SIZE> prime; void runSieve(){ assert(_SE_SIZE != 1); prime = 0; prime.flip(); prime[0] = prime[1] = 0; for(int i=4;i<_SE_SIZE; i+=2) prime[i]=0; for(long long i=3;i*i<_SE_SIZE; i+=2) if(prime[i]) for(int j=i*i;j<_SE_SIZE;j+=i) prime[j]=0;}
// END CUT - Sieve of Eratosthenes

// BEGIN CUT - Binary Search - O(logN) - find the point where it goes from untrue to true... always false at low
long long  binarySearch(long long  low, long long high, bool (* _target) (long long t1)){ while(low < high){ long long mid = low + (high - low) / 2; if(_target(mid)) high = mid; else low = mid+1;} return low;}
long double binarySearch(long double low, long double high, bool (* _target) (long double t1)){ while(low < high-eps){ long double mid = low + (high - low) / 2.0; if(_target(mid)) high = mid; else low = mid; }return low;}
// END CUT - Binary Search

// BEGIN CUT - Ternary Search - O(logN)
long long ternarySearch(long long low, long long high, bool (* _better) (long long t1, long long t2)){ while(low < high - 3){ long long p1 = low + (high - low) / 3, p2 = low + 2 * (high - low) / 3; if(_better(p1, p2)) high = p2; else low = p1; } if(_better(low,low+1)) return low; else if(_better(low+1,low+2)) return low+1; else if(_better(low+2,low+3)) return low+2; return low+3;}
long double ternarySearch(long double low, long double high, bool (* _better) (long double t1, long double t2)){ while(low < high-eps){ long double p1 = low + (high - low) / 3.0, p2 = low + 2 * (high - low) / 3.0; if(_better(p1, p2)) high = p2; else low = p1; } return low;}
// END CUT - Ternary Search

// BEGIN CUT - Matrix Multiplication/Exponentiation - O(N^3) / O(N^3logP)
template <class T>
vector<vector<T> > matrixMultiply(const vector<vector<T> > & A, const vector<vector<T> > &B){ int nR = A.size(), nC = B[0].size(), com = B.size();  vector<vector<T> > retMatrix; if(A[0].size() != com) cerr << "Fatal Matrix Error" << endl, exit(0); FOR(i,0,nR){ vector<T> row; FOR(j,0,nC){ T sum = 0; FOR(k,0,com) sum += A[i][k] * B[k][j]; row.push_back(sum);} retMatrix.push_back(row); } return retMatrix;}
template <class T>
vector<vector<T> > matrixExponentiate(vector<vector<T> > matrix, int power){ if(power == 1) return matrix; int size = matrix.size(); vector<vector<T> > current(size,vector<T>(size,0)); FOR(i,0,size) current[i][i] = 1; while(power > 0){ if(power & 1) current = matrixMultiply(current,matrix); matrix = matrixMultiply(matrix,matrix); power >>=1;   } return current;}
template <class T>
vector<vector< T> > matrixTranspose(vector<vector<T> > matrix){}
//END CUT - Matrix Multiplication/Exponentiation

// BEGIN CUT - Linear Programming
const int LP_GTE=1, LP_LTE=-1, LP_EQ = 0, LP_MAX=1, LP_MIN=0;
struct slackForm{
   int nV, nC; long double val; vector<int> nonBasic, basic;
   vector<vector<long double> > aCoef; vector<long double> bCoef, cCoef;
   slackForm(int v=0, int c=0):nV(v),nC(c),val(0){ nonBasic=vector<int>(nV), basic=vector<int>(nC),aCoef = vector<vector<long double> >(nC,vector<long double>(nV,0)),bCoef=vector<long double>(nC), cCoef=vector<long double>(nV,0);}
   void print() const{ cout << "---------SLACK-------------\n"; cout << "NV/NC: " << nV << " " << nC << " -> " << val << endl; printArray(nonBasic); printArray(basic); cout << endl; printArray(aCoef); cout << endl; printArray(bCoef); printArray(cCoef); cout << endl;}
};

struct linearProgrammer{
   int numVars; vector<int> minus; vector<bool> used, nnConstrained;
   vector<pair<long double, int> > mmEquation; int mmType;
   vector<vector<pair<long double, int> > > consEquations;
   vector<long double> consRHS; vector<int> consTypes;
   linearProgrammer(int nV):numVars(nV){minus = vector<int>(nV,-1); used = nnConstrained = vector<bool>(nV,false); mmType = LP_MAX;}
   void setMMType(int mmt){mmType=mmt;}
   bool addMMPair(long double coef, int index){ if(index>=numVars) return false; mmEquation.push_back(make_pair(coef,index)); used[index] = true; return true; }
   void addConsEquation(int type, long double rhs){ consEquations.push_back(vector<pair<long double, int> >()); consTypes.push_back(type);consRHS.push_back(rhs);}
   bool addConsPair(int index, long double coef, int var){ if(index>=consEquations.size() || var >= numVars) return false; consEquations[index].push_back(make_pair(coef,var)); used[var] = true; return true;}
   bool addNNConstraint(int index) { return(index>=numVars)?false:nnConstrained[index]=true;}
   void toStandard(){ if(mmType == LP_MIN) FOR(i,0,mmEquation.size()) mmEquation[i].first*=-1; mmType = LP_MAX; FOR(i,0,numVars) if(!used[i]) nnConstrained[i] = true; else if(!nnConstrained[i]){ minus.push_back(-1), nnConstrained.push_back(true), used.push_back(true); minus[i] = numVars++; nnConstrained[i] = true; FOR(j,0,mmEquation.size()) if(mmEquation[j].second==i) addMMPair(-mmEquation[j].first,numVars-1); FOR(j,0,consEquations.size()) FOR(k,0,consEquations[j].size()) if(consEquations[j][k].second==i) addConsPair(j,-consEquations[j][k].first,numVars-1); } FOR(i,0,consEquations.size()){ if(consTypes[i] == LP_EQ){ consTypes.push_back(LP_GTE); consRHS.push_back(consRHS[i]); consEquations.push_back(consEquations[i]); } else if(consTypes[i] == LP_GTE){ consRHS[i] = -consRHS[i]; FOR(j,0,consEquations[i].size()) consEquations[i][j].first*=-1; } consTypes[i] = LP_LTE;}}
   void print() const{  cout << "NV/NC: " << numVars << " " << consEquations.size() << endl; FOR(i,0,numVars) cout << "(" << minus[i] << "," << used[i] << " " << nnConstrained[i] <<") "; cout << endl; cout << ((mmType == LP_MIN)?"minimizing: ":"maximizing: "); FOR(i,0,mmEquation.size()) { if(i>0 && mmEquation[i].first > 0) cout << "+"; cout << mmEquation[i].first << "X[" << mmEquation[i].second << "]";} cout << endl << endl; FOR(i,0,consEquations.size()){ FOR(j,0,consEquations[i].size()) { if(j > 0 && consEquations[i][j].first > 0) cout << "+"; cout << consEquations[i][j].first << "X[" << consEquations[i][j].second << "]";} if(consTypes[i]==LP_LTE) cout << "<"; else if(consTypes[i]==LP_GTE) cout << ">"; cout << "=" << consRHS[i] << endl;}} 
   slackForm toSlack(){ toStandard(); slackForm sf(numVars,consEquations.size()); FOR(i,0,numVars) sf.nonBasic[i] = i; FOR(i,0,consEquations.size()){ sf.basic[i] = numVars+i; sf.bCoef[i] = consRHS[i]; FOR(j,0,consEquations[i].size()) sf.aCoef[i][consEquations[i][j].second] += consEquations[i][j].first;} FOR(i,0,mmEquation.size()) sf.cCoef[mmEquation[i].second] += mmEquation[i].first; return sf;}
};

slackForm pivot(const slackForm &input, int rowL, int colE){
   slackForm output = input; output.bCoef[rowL] = input.bCoef[rowL] / input.aCoef[rowL][colE]; FOR(i,0,input.nV) if(i!=colE) output.aCoef[rowL][i] = input.aCoef[rowL][i] / input.aCoef[rowL][colE];    
   output.aCoef[rowL][colE] = 1 / input.aCoef[rowL][colE]; FOR(i,0,input.nC) if(i!=rowL){ output.bCoef[i] = input.bCoef[i] - input.aCoef[i][colE] * output.bCoef[rowL]; FOR(j,0,input.nV) if(j!=colE) output.aCoef[i][j] = input.aCoef[i][j] - input.aCoef[i][colE] * output.aCoef[rowL][j]; output.aCoef[i][colE] = -input.aCoef[i][colE] * output.aCoef[rowL][colE];}
   output.val = input.val + input.cCoef[colE] * output.bCoef[rowL];FOR(i,0,input.nV) if(i!=colE) output.cCoef[i] = input.cCoef[i] - input.cCoef[colE] * output.aCoef[rowL][i]; output.cCoef[colE] = -input.cCoef[colE] * output.aCoef[rowL][colE]; output.nonBasic[colE] = input.basic[rowL], output.basic[rowL] = input.nonBasic[colE]; return output;
}

void simplexValidSlack(slackForm & sF, vector<long double> & xArray, bool &bounded, long double &value){
    bounded = true; int posit = -1; FOR(i,0,sF.nV) if(sF.cCoef[i]>eps){ posit=i; break;} // sF.print();
    while(posit!=-1){ int bestI = -1; long double bestV = 0; bool zeroed = false; int trying = posit;
     while(trying < sF.nV){ if(sF.cCoef[trying]<eps || sF.nonBasic[trying] > sF.nonBasic[posit]){trying++;continue;}
         int tBestI = -1; FOR(i,0,sF.basic.size()) if(sF.aCoef[i][trying] > eps){ long double value = sF.bCoef[i] / sF.aCoef[i][trying];  if(zeroed){ if(sF.bCoef[i] < eps && (tBestI == -1 || sF.basic[tBestI] > sF.basic[i])) tBestI = i;continue; } else if(sF.bCoef[i] < eps) {zeroed=true, tBestI = i; continue;} if(tBestI == -1) tBestI = i, bestV = value; else if(bestV > value) bestV = value, tBestI=i;}//	 cout << "Trying: " << trying << " -> " << tBestI << " " << zeroed << endl;
         if(tBestI != -1 || !zeroed) bestI = tBestI, posit = trying; if(!zeroed && bestI != -1) break; trying++;}
         if(!zeroed && bestI == -1) { bounded = false; return;} sF = pivot(sF,bestI,posit); // cout << "Pivoting on " << bestI << " " << posit << endl; sF.print();
     posit=-1; FOR(i,0,sF.nV) if(sF.cCoef[i]>eps){ posit=i; break;}} xArray = vector<long double>(sF.nV,0); FOR(i,0,sF.bCoef.size()) if(sF.basic[i]<sF.nV) xArray[sF.basic[i]]=sF.bCoef[i]; value = sF.val;
}

void initializeSimplex(linearProgrammer standard, slackForm & retSF, bool &feasible){
   slackForm stSlack = standard.toSlack(); feasible = true; int mnIndex = 0; FOR(i,1,standard.consEquations.size()) if(standard.consRHS[mnIndex] > standard.consRHS[i]) mnIndex = i; if(standard.consRHS[mnIndex] > -eps) { retSF = stSlack; return;}
   linearProgrammer aux(standard.numVars+1); aux.setMMType(LP_MAX); aux.addMMPair(-1,standard.numVars); aux.consEquations = standard.consEquations; aux.consTypes = standard.consTypes; aux.consRHS = standard.consRHS; FOR(i,0,aux.consEquations.size()) aux.addConsPair(i,-1,standard.numVars); aux.addNNConstraint(standard.numVars);
   retSF = pivot(aux.toSlack(),mnIndex,standard.numVars); vector<long double> xArray; bool bounded; long double value; simplexValidSlack(retSF,xArray,bounded,value); if(!bounded || abs(value) > eps){ feasible = false; return;}
   FOR(i,0,retSF.nV) if(retSF.nonBasic[i]==standard.numVars){ FOR(j,0,retSF.nC) retSF.aCoef[j].erase(retSF.aCoef[j].begin()+i); retSF.nonBasic.erase(retSF.nonBasic.begin() + i); retSF.nV--; break;}
   retSF.cCoef = vector<long double>(retSF.nV,0); retSF.val = 0; FOR(i,0,retSF.nV) if(retSF.nonBasic[i] < retSF.nV) retSF.cCoef[i] += stSlack.cCoef[retSF.nonBasic[i]];
   FOR(i,0,retSF.nC) if(retSF.basic[i] < retSF.nV){ FOR(j,0,retSF.nV) retSF.cCoef[j] += -stSlack.cCoef[retSF.basic[i]] * retSF.aCoef[i][j]; retSF.val += retSF.bCoef[i] * stSlack.cCoef[retSF.basic[i]]; }
}

void simplex(const linearProgrammer & original, vector<long double> & xArray, bool &feasible, bool & bounded, long double &value){
    bounded = true; feasible = true; linearProgrammer standard = original; standard.toStandard();  //    standard.print();
    if(standard.consEquations.size()==0) FOR(j,0,standard.mmEquation.size()) if(standard.mmEquation[j].first>0){ bounded = false; break; }  if(!bounded) return; slackForm sF; initializeSimplex(standard,sF,feasible); if(!feasible) return; simplexValidSlack(sF,xArray,bounded,value);
    FOR(i,0,original.numVars){ int next = standard.minus[i]; if(next!=-1) xArray[i] -= xArray[next];} xArray.resize(original.numVars); value = 0; FOR(i,0,original.mmEquation.size()) value += original.mmEquation[i].first * xArray[original.mmEquation[i].second];
}
// END CUT - Linear Programming

// BEGIN CUT - Maxflow - O(E * maxflow)
#define MF_NETWORK_SIZE 1
vector<int> _MFadjlist[MF_NETWORK_SIZE];
int _MFflow[MF_NETWORK_SIZE][MF_NETWORK_SIZE];
int _MFcapacity[MF_NETWORK_SIZE][MF_NETWORK_SIZE];
bool _MFvisited[MF_NETWORK_SIZE];
void initMF(){ memset(_MFflow,0,sizeof(_MFflow)); memset(_MFcapacity,0,sizeof(_MFcapacity)); FOR(i,0,MF_NETWORK_SIZE) _MFadjlist[i].clear(); }
void reset(){ memset(_MFflow,0,sizeof(_MFflow));}
bool aug_path_dfs(int cur, int snk){ if(_MFvisited[cur]) return false; if(snk == cur) return true; _MFvisited[cur] = true; FOR(i,0,_MFadjlist[cur].size()){ int tmp = _MFadjlist[cur][i]; if(_MFflow[cur][tmp] >= _MFcapacity[cur][tmp]) continue; _MFflow[cur][tmp]++; _MFflow[tmp][cur]--; if(aug_path_dfs(tmp,snk)) return true; _MFflow[cur][tmp]--; _MFflow[tmp][cur]++; } return false; }
void cullPath(const vector<int> &lst){ FOR(i,1,lst.size()) _MFcapacity[lst[i-1]][lst[i]] = 0; }
void restorePath(const vector<int> &lst){ FOR(i,1,lst.size()) _MFcapacity[lst[i-1]][lst[i]] = 1; }
int maxFlow(int src, int snk){ assert(MF_NETWORK_SIZE!=1); int ret = 0; while(true){ memset(_MFvisited,false,sizeof(_MFvisited)); if(!aug_path_dfs(src,snk)) break;  ret++; } return ret; }
void addMFConnection(int left, int right, int cap){ _MFflow[left][right] = _MFflow[right][left] = 0; _MFcapacity[left][right] = cap; _MFcapacity[right][left] = 0; _MFadjlist[left].push_back(right); _MFadjlist[right].push_back(left);}
// END CUT - Maxflow

// BEGIN CUT - Geometry Library = O(dimensions)
template <class T>
T distanceSquared(const vector<T> &p1, const vector<T> &p2){ T ret = 0; FOR(i,0,p1.size()) ret += SQ(p2[i] - p1[i]); return ret;}
template <class T>
inline T distanceSquared(const pair<T,T> p1, const pair<T,T> p2){ return SQ(p2.first - p1.first) + SQ(p2.second - p1.second);}
bool line_intersection2D(const vector<double> &p1, const vector<double> &p2, const vector<double> &q1, const vector<double> &q2, vector<double> &r, bool &colinear){
    colinear = false; r = vector<double>(2,0); double N1, N2, D, u1, u2; N1 = (q2[0] - q1[0]) * (p1[1] - q1[1]) - (q2[1] - q1[1]) * (p1[0] - q1[0]); N2 = (p2[0] - p1[0]) * (p1[1] - q1[1]) - (p2[1] - p1[1]) * (p1[0] - q1[0]);  D  = (q2[1] - q1[1]) * (p2[0] - p1[0]) - (q2[0] - q1[0]) * (p2[1] - p1[1]);
    if(fabs(D) > eps) { u1 = N1 / D; u2 = N2/D; if(u1 < -eps || u1 > 1+eps || u2 < -eps || u2 > 1+eps) return false; r[0] = p1[0] + (p2[0] - p1[0]) * u1;  r[1] = p1[1] + (p2[1] - p1[0]) * u1; return true;} 
    if(fabs(N1) > eps && fabs(N2) > eps) return false; else colinear = true; if(p1[0] >= min(q1[0],q2[0]) && p1[0] <= max(q1[0],q2[0]) && p1[1] >= min(q1[1],q2[1]) && p1[1] <= max(q1[1],q2[1]))  { r = p1; return true;}  if(p2[0] >= min(q1[0],q2[0]) && p2[0] <= max(q1[0],q2[0]) && p2[1] >= min(q1[1],q2[1]) && p2[1] <= max(q1[1],q2[1]))  { r = p2; return true;} return false;
}
bool line_intersection2D(const pair<double, double> &p1, const pair<double,double> &p2, const pair<double,double> &q1, pair<double,double> &q2, pair<double, double> &r, bool &colinear){ vector<double> pv1(2), pv2(2), qv1(2), qv2(2), rv; pv1[0] = p1.first; pv1[1] = p1.second; pv2[0] = p2.first; pv2[1] = p2.second; qv1[0] = q1.first; qv1[1] = q1.second; qv2[0] = q2.first; qv2[1] = q2.second; bool ret = line_intersection2D(pv1,pv2,qv1,qv2,rv,colinear); r.first = rv[0]; r.second = rv[1]; return ret;}
template <class T>
T dot_product(vector<T> &p1, vector<T> &p2){ T ret = 0; FOR(i,0,p1.size()) ret += p1[i] * p2[i];  return ret; }
template <class T>
vector<T> cross_product(vector<T> &p1, vector<T> &p2){ vector<T> ret(3);    ret[0] = p1[1] * p2[2] - p1[2] * p2[1]; ret[1] = p1[2] * p2[0] - p1[0] * p2[2]; ret[2] = p1[0] * p2[1] - p1[1] * p2[0]; return ret; }
template <class T>
vector<T> cross_product(pair<T,T> &p1, pair<T,T> &p2){ vector<T> v1(3), v2(3); v1[0] = p1.first; v1[1] = p1.second; v2[0] = p2.first; v2[1] = p2.second; return cross_product(v1,v2); }
// END CUT - Geometry Library

// BEGIN CUT - Bellman-Ford - O(V * E)
#define BF_NETWORK_SIZE 1
struct BFedge{ int src, dest, cost; };
vector<BFedge> _BFedgeList;
int _BFdistance[BF_NETWORK_SIZE]; 
void initBF(){_BFedgeList.clear();}
void addBFEdge(int from, int to, int cost) {  BFedge bfe; bfe.src = from; bfe.dest = to; bfe.cost = cost; _BFedgeList.push_back(bfe);}
bool bellman_ford(int src, int NV, int *_array = _BFdistance){ assert(BF_NETWORK_SIZE!=1); FOR(i,0,NV){ _array[i] = INF;} _array[src] = 0; FOR(i,0,NV) FOR(j,0,_BFedgeList.size()) if(_array[_BFedgeList[j].src] < INF){ int nD = _array[_BFedgeList[j].src] + _BFedgeList[j].cost; _array[_BFedgeList[j].dest] = min(nD,_array[_BFedgeList[j].dest]); } FOR(i,0,_BFedgeList.size()) if(_array[_BFedgeList[i].dest] > _array[_BFedgeList[i].src] + _BFedgeList[i].cost) return false;return true;}
// END CUT - Bellman-Ford

// BEGIN CUT - Graph Manipulation - O(elements)
vector<string> rotateR(const vector<string> &orig){ vector<string> ret(orig[0].length()); FOR(i,0,orig[0].length()) FOR(j,0,orig.size()) ret[i].push_back(orig[orig.size()-j-1][i]); return ret;}
vector<string> flipH(const vector<string> &orig){ vector<string> ret = orig; FOR(i,0,orig.size()) FOR(j,0,orig[0].length()) ret[i][j] = orig[i][orig.size()-j-1]; return ret;}
// END CUT - Graph Manipulation

//BEGIN CUT - Choose Function - O(min(B,T-B)^2)
long long choose(long long T, long long B){ long long ret = 1;  vector<long long> top, bottom; if(T<B || B<0) return -1; B = min(B,T-B); FOR(i,0,B){ top.push_back(T-i); bottom.push_back(i+1); } FOR(i,0,top.size()) FOR(j,0,bottom.size()){ if(top[i]==1) break; long long g = gcd(top[i],bottom[j]); top[i]/=g; bottom[j]/=g; if(bottom[j]==1){ swap(bottom[bottom.size()-1],bottom[j--]); bottom.pop_back();} } FOR(i,0,top.size()) ret*=top[i]; return ret;}
// END CUT - Choose Function

// BEGIN CUT - Flood Fill - O(elements)
#define _FLD_ROWS 1
#define _FLD_COLS 1
int fdr[] = {0,0,-1,1}, fdc[] = {-1,1,0,0};
bool floodmatrix[_FLD_ROWS][_FLD_COLS];
void initFlood(){ MEMSET(floodmatrix,false);}
int flood(int r, int c, int nR, int nC, bool (*invalid)(int,int)){ if(r<0 || c<0 || r>=nR || c>=nC || floodmatrix[r][c] || invalid(r,c)) return 0; floodmatrix[r][c] = true; int ret =1;      FOR(i,0,4) ret += flood(r+fdr[i],c+fdc[i],nR,nC,invalid); return ret;}
// END CUT - Flood Fill

// BEGIN CUT - BFS - O(states)
#define _BFS_ROWS 1
#define _BFS_COLS 1
int bfsdr[] = {0,0,-1,1}, bfsdc[] = {-1,1,0,0};
int bfsmatrix[_BFS_ROWS][_BFS_COLS];
bool _BFSvalidMove(int fR, int fC, int dR, int dC){
   cout << "NEED TO PUT SOME MORE CODE HERE" << fR << " " << fC << " " << dR << " " << dC << endl;
   return true;
}
int bfs(int r, int c, int numRows, int numCols, int targetR=INF, int targetC=INF){
       memset(bfsmatrix,-1,sizeof(bfsmatrix));
       queue<int>left; left.push(r); left.push(c); bfsmatrix[r][c] = 0; if(targetR==0&&targetC==0) return 0;
       while(!left.empty()){
         int tR, tC, d, nR, nC; tR =left.front(); left.pop(); tC = left.front(); left.pop(); d = bfsmatrix[tR][tC];
         FOR(i,0,4){
             nR = tR + bfsdr[i], nC = tC + bfsdc[i]; if(nR<0||nC<0||nR>=numRows||nC>=numCols||bfsmatrix[nR][nC]!=-1||!_BFSvalidMove(tR,tC,nR,nC)) continue;
             bfsmatrix[nR][nC]=(d+1); left.push(nR); left.push(nC); if(nR==targetR&&nC==targetC) return d+1;
         }
      }
      return -1;
}
// END CUT - BFS

int N;
int _times;
int diff[1000];

int main(){
  cin >> _times;
  FOR(_t,1,_times+1){
    cout << "Case #" << _t << ": ";
    cin >> N;
    int last, next;
    cin >> last;
    FOR(i,0,N-1) { cin >> next; if(next < last) next+= 10007;  diff[i] = next-last; last = next%10007;}
    //FOR(i,0,N-1) { cout << diff[i] << endl;}
    if(N <= 3) cout << "UNKNOWN" << endl;
    else if(N == 4 && diff[0]==diff[2]) cout << "UNKNOWN" << endl;
    else if(N == 4) cout << (last + diff[1])%10007 << endl;
    else if(diff[1]!=diff[3] && diff[0]==diff[2]) cout << (last + diff[0])%10007 << endl;
    else cout << "UNKNOWN" << endl;
  }
  return 0;
}
