#include <vector>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define fr(i, n) for(i = 0; i < (n); i++)
#define frr(i, n) for(int i = 0; i < (n); i++)

typedef long long ll;
#define mp make_pair
typedef vector<int> VI;
typedef vector<string> VS;
typedef istringstream ISS;
typedef ostringstream OSS;
#define _cl(x) memset(x, 0, sizeof(x))
#define _rs(x) memset(x, -1, sizeof(x))

ll R, K, N;
ll a[10000];
ll val[10000];
ll stop[10000];

void read(ifstream &fin)
{
 fin >> R >> K >> N;

 frr(i, N)
  fin >> a[i];
}

void proc(ofstream &fout)
{
 frr(i, N) {
  ll s = 0;
  int j;
  fr(j, N) {
   if(s + a[(i + j) % N] > K)
    break;

   s += a[(i + j) % N];
  }

  stop[i] = (i + j) % N;
  val[i] = s;
 }

 int n = 0;
 ll res = 0;

 frr(i, R) {
  res += val[n];
  n = stop[n];
 }

 fout << res << endl;
}

int main()
{
 int i;
 int NT;

 ifstream fin("input.txt");
 ofstream fout("output.txt");
 string ln;

 getline(fin, ln);
 istringstream is(ln);
 is >> NT;

 fr(i, NT)
 {
  read(fin);
  fout << "Case #" << i + 1 << ": ";
  cout << "Case #" << i + 1 << endl;
  proc(fout);
 }

 return 0;
}
