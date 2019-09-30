#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <stdint.h>

using std::vector;
using std::string;

typedef int64_t ll;

ll gcd(ll x, ll y) {
 top:
  if (x == 0) {
    return y;
  }
  ll tmp = y % x;
  y = x;
  x = tmp;
  goto top;
}

ll lcm(ll x, ll y, ll h) {
  if (x == 0 || y == 0) {
    return 0;
  }
  ll g = gcd(x, y);
  ll b = y / g;
  // is b * x <= h ?
  // iff floor(h / x) >= b
  if (h / x >= b) {
    return b * x;
  } else {
    return 0;
  }  
}

int main() {
  int T;
  std::cin >> T;
  for (int tcase = 1; tcase <= T; ++tcase) {
    ll N, L, H;
    std::cin >> N >> L >> H;

    vector<ll> f;
    for (ll i = 0; i < N; ++i) {
      ll x;
      std::cin >> x;
      f.push_back(x);
    }

    std::sort(f.begin(), f.end());

    ll gc = f[N-1];
    ll lc = f[0];

    vector<ll> gs(N);
    vector<ll> ls(N);
    gs[N-1] = gc;
    ls[0] = lc;

    for (ll i = 1; i < N; ++i) {
      gc = gcd(gc, f[N-i-1]);
      gs[N-i-1] = gc;
      lc = lcm(lc, f[i], H);
      ls[i] = lc;
    }

    ll output = 0;
    // first consider gcd

    if (L <= gc) {
      ll k = 1;
      while (k * k <= gc) {
	if (gc % k == 0) {
	  // a factor
	  if (L <= k && k <= H) {
	    if (output == 0 || (output != 0 && output > k)) {
	      output = k;
	    }
	  }
	  ll k2 = gc / k;
	  if (L <= k2 && k2 <= H) {
	    if (output == 0 || (output != 0 && output > k2)) {
	      output = k2;
	    }
	  }
	}

	++k;
      }
    }


    // then consider lcm
    if (lc != 0) {
      if (L % lc == 0) {
	if (output == 0 || (output != 0 && L < output)) {
	  output = L;
	}
      } else {
	ll nex = L + (lc - (L % lc));
	if (nex <= H && nex >= L) {
	  if (output == 0 || (output != 0 && nex < output)) {
	    output = nex;
	  }
	}
      }
    }

    // then consider in between (all praise the example input)

    ll lastoutput = 0;
    int pos = 0;
    ll k = 1;
    while (k * k <= gs[N-1]) {
      if (pos == N-1 || ls[pos] == 0) {
	goto done;
      }
      //      std::cout << "k = " << k << ", pos = " << pos << ", ls[pos+1] = " << ls[pos + 1] << std::endl;

      if (ls[pos+1] != 0 && k == ls[pos+1]) {
	++pos;
	continue;
      }

      if (gs[pos + 1] % k == 0 && k % ls[pos] == 0) {
	if (L <= k && k <= H) {
	  lastoutput = k;
	  goto done;
	}
      }

      ++k;
    }

    while (k > 0) {
      if (pos == N-1 || ls[pos] == 0) {
	goto done;
      }
      //      std::cout << "k = " << k << ", pos = " << pos << ", ls[pos + 1] = " << ls[pos + 1] << ", gs[N-1] = " << gs[N-1] << std::endl;


      if (ls[pos+1] != 0 && gs[N-1] / k >= ls[pos+1]) {
	++pos;
	continue;
      }

      ll k2 = gs[N-1] / k;

      if (gs[pos + 1] % k2 == 0 && k2 % ls[pos] == 0) {
	if (L <= k2 && k2 <= H) {
	  lastoutput = k2;
	  goto done;
	}
      }

      --k;
    }


  done:
    //    std::cout << "lastoutput " << lastoutput << "\n";

    if (lastoutput != 0 && (output == 0 || lastoutput < output)) {
      output = lastoutput;
    }

    std::cout << "Case #" << tcase << ": ";
    if (output != 0) {
      std::cout << output;
    } else {
      std::cout << "NO";
    } 
    std::cout << "\n";
  }
}

