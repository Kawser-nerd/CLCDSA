#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<i_i, int> p_i;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
template<class T> using vv=vector<vector< T > >;

template<class T>
double volume(T r, int h) {
  double vol = M_PI;
  vol *= (r*r*h);
  vol /= 3;
  return vol;
}

template<class T>
double volume(T r, int h, int h_out) {
  double r_out = ((double)r) * h_out /h;
  return volume(r, h) - volume(r_out, h_out);
}

int main() {
  int n, q;
  cin >> n >> q;
  vvi xrh;
  for (int i = 0 ; i < n ; i++) {
    int x_b, r, h;
    cin >> x_b >> r >> h;
    int x_t = x_b + h;
    vi tmp = {x_b, x_t, r, h};
    xrh.push_back(tmp);
  }
  
  vector<ll> vol_ll;
  vector<double> vol_d;
  for (int i = 0 ; i < q ; i++) {
    int a, b;
    cin >> a >> b;
    double vf = 0.0;
    ll vll = 0;
    for (int in = 0 ; in < n ; in++) {
      if (xrh[in][0] >= b || xrh[in][1] <= a) { continue; }
      if (xrh[in][1] <= b) {
        if (xrh[in][0] >= a) {
          double v_tmp = volume(xrh[in][2], xrh[in][3]);
          vll += (ll)v_tmp;
          vf += (v_tmp - (ll)v_tmp);
          continue;
        } else {
          int h_in = xrh[in][1] - a;
          double r = ((double)xrh[in][2]) * h_in / xrh[in][3];
          double v_tmp = volume(r, h_in);
          vll += (ll)v_tmp;
          vf += (v_tmp - (ll)v_tmp);
          continue;
        }
      }
      if (xrh[in][0] >= a) {
        double v_tmp = volume(xrh[in][2], xrh[in][3], xrh[in][1] - b);
        vll += (ll)v_tmp;
        vf += (v_tmp - (ll)v_tmp);
        continue;
      } else {
        int h = xrh[in][1] - a;
        int h_out = xrh[in][1] - b;
        double r = ((double)xrh[in][2]) * h / xrh[in][3];
        double v_tmp = volume(r, h, h_out);
        vll += (ll)v_tmp;
        vf += (v_tmp - (ll)v_tmp);
      }
    }
    vll += (ll)vf;
    vf -= (ll)vf;
    vol_ll.push_back(vll);
    vol_d.push_back(vf);
  } 

  for (int i = 0 ; i < q ; i++) {
    printf("%lld.%03d\n", vol_ll[i], (int)(vol_d[i]*1000));
  }

  return 0;
}