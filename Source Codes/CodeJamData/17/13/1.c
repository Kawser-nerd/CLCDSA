#define DEBUG 0

#include <bits/stdc++.h>
using namespace std;

int ans, Hd, Ad, Hk, Ak, B, D;

struct move {
  int hd, ad, hk, ak, turn;
};

bool operator<(const move& lhs, const move& rhs)
{
  if(lhs.hd != rhs.hd)
    return lhs.hd < rhs.hd;
  if(lhs.ad != rhs.ad)
    return lhs.ad < rhs.ad;
  if(lhs.hk != rhs.hk)
    return lhs.hk < rhs.hk;
  return lhs.ak < rhs.ak;
}

int main() {
  int tc, cn;
  scanf("%d", &tc);
  for(cn = 1; cn <= tc; cn++) {
    scanf("%d%d%d%d%d%d", &Hd, &Ad, &Hk, &Ak, &B, &D);
    queue<move> q;
    set<move> s;
    move m;
    m.hd = Hd, m.ad = Ad, m.hk = Hk, m.ak = Ak, m.turn = 0;
    q.push(m);
    s.insert(m);
    ans = INT_MAX;
    while(!q.empty()) {
      m.hd = q.front().hd;
      m.ad = q.front().ad;
      m.hk = q.front().hk;
      m.ak = q.front().ak;
      m.turn = q.front().turn;
      q.pop();
      if(DEBUG)
	printf("hd = %d, ad = %d, hk = %d, ak = %d, turn = %d\n", m.hd, m.ad, m.hk, m.ak, m.turn);
      move nm;
      nm.turn = m.turn + 1;      
      //attack
      if(m.ad >= m.hk) {
	ans = m.turn + 1;
	break;
      }
      nm.hd = m.hd - m.ak; //attaked by knight before next turn
      if(nm.hd > 0) {
	nm.ad = m.ad;
	nm.hk = m.hk - m.ad;
	nm.ak = m.ak;
	if(s.find(nm) == s.end()) {
	  s.insert(nm);
	  q.push(nm);
	}
      }
      //buff
      if(nm.hd > 0 && B > 0) {
	nm.ad = m.ad + B;
	nm.hk = m.hk;
	nm.ak = m.ak;
	if(s.find(nm) == s.end()) {
	  s.insert(nm);
	  q.push(nm);
	}
      }
      //Cure
      if(m.hd < Hd && m.ak > 0 && Hd - m.ak > 0) {
	nm.hd = Hd - m.ak;
	nm.ad = m.ad;
	nm.hk = m.hk;
	nm.ak = m.ak;
	if(s.find(nm) == s.end()) {
	  s.insert(nm);
	  q.push(nm);
	}
      }
      //Debuff
      if(D > 0 && m.ak > 0 && m.hd - max(m.ak - D, 0) > 0) {
	nm.ak = max(m.ak - D, 0);
	nm.hd = m.hd - nm.ak;
	nm.ad = m.ad;
	nm.hk = m.hk;
	if(s.find(nm) == s.end()) {
	  s.insert(nm);
	  q.push(nm);
	}
      }
    }
    printf("Case #%d: ", cn);
    if(ans == INT_MAX)
      printf("IMPOSSIBLE\n");
    else
      printf("%d\n", ans);
  }
}
