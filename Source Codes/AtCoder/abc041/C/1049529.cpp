#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <numeric>
//ranker
using namespace std;

#define REPS(i, a, n) for (int i = (a); i < (n); ++i)
#define REP(i, n) REPS(i, 0, n)
#define RREP(i, n) REPS(i, 1, n + 1)
#define DEPS(i, a, n) for (int i = (a); i >= n; --i)
#define DEP(i, n) DEPS(i, n, 0)

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using pii = pair<int, int>;
using pis = pair<int, string>;
using psi = pair<string, int>;
using D = double;


//??????
void sort2vectors(vector<int> &av, vector<int> &bv)
{
        int n = av.size();
        vector<int> p(n), av2(n), bv2(n);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(), [&](int a, int b) { return av[a] < av[b]; });
        for (int i = 0; i < n; i++) {
                av2[i] = av[p[i]];
                bv2[i] = bv[p[i]];
        }
        av = av2;
        bv = bv2;
}

//?????
int gcd(int a, int b)
{
    int c;
    if (a < b) {
        a+=b; b=a-b; a-=b;
    }
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

//?????
int lcm(int x, int y)
{
    return (x * y / gcd(x, y));
}

int isPrime(int x){
  int i;
  if(x < 2) return 0;
  else if(x == 2) return 1;
  if( x%2 == 0) return 0;
  for(i = 3; i*i <= 2; i += 2){
    if(x%i == 0) return 0;
  }
  return 1;
}


const int pmax = 10000000;
bool isPrime_table[pmax];
//const????????????

void eratos(void){
  int i, j;
  double sqrtmax=sqrt(pmax);

  REP(k, pmax) isPrime_table[k] = true; /* Initialization */

  /* Sieve process  */
  isPrime_table[0] = false;
  isPrime_table[1] = false;
          /* 0 and 1 are not prime. */
  for (i=2; i <= sqrtmax; i++){
    if (isPrime_table[i]==true){   /* i is prime. */
      for (j=i; i*j<pmax; j++){
        isPrime_table[i*j] = false; /* multiples of i are not prime. */
      }
    }
  }
}

//??????????
//abs(dx[i]+dy[j])==1???
int dx[3]={-1, 0, 1};
int dy[3]={-1, 0, 1};
int W0, H0;
int  masu0[100][100]={0};
int cnt0;

int dfs(int a, int b){
  masu0[a][b] = 2;
  REP(i, 3)REP(j, 3){
    a = a+dx[i];
    b = b+dy[j];
    if(masu0[a][b]== 1 && a >= 0 && a < W0 && b >= 0 && b < H0){
    dfs(a, b);
  }
  }
  return 1;
}

//????????str.substr(i, 5)
//?????? stoi, stod ?to_string
//???memset
//????????
//dp
//map?set????
//str.find std::npos
//auto???&??
//?????????tolower touuper
//??????
const string abet("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");

static const long long int MOD = 1000000007;

static const double PI=3.1415926535897932;


int main(void){

  cin.tie(0);
  ios::sync_with_stdio(false);


  int n;
  cin >> n;
  vector<pair<int,int>> a(n); // height, num
  REP(i,n){
    int h;
    cin >> h;
    a[i] = make_pair(h, i+1);
  }
  sort(a.begin(), a.end(), greater<pii>());
  for(auto& itr : a) cout << itr.second << endl;

  return 0;

}