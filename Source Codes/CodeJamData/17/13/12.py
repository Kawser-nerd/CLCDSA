INF = 10**12

_T = int(raw_input())
for _t in range(1, _T+1):
  Hd, Ad, Hk, Ak, B, D = map(int, raw_input().split())
  
  res = INF

  if B == 0:
    Bmax = 1
  else:
    Bmax = 101-Ad
  if D == 0:
    Dmax = 1
  else:
    Dmax = Ak+1
  for bs in range(Bmax):
    for ds in range(Dmax):
      hd, ad, hk, ak = Hd, Ad, Hk, Ak
      b, d = 0, 0
      S = set()
      n = 0
      while hd > 0 and hk > 0 and (hd, ad, hk, ak) not in S:
        S.add((hd, ad, hk, ak))
        n += 1
# Win
        if ad >= hk:
          hk = 0
          break
# Should debuff
        if d < ds:
# ... but needs heal
          if ak - D >= hd:
            hd = Hd - ak
          else:
            ak = max(ak-D, 0)
            hd -= ak
            d += 1
          continue
# Needs heal now
        if ak >= hd:
          hd = Hd - ak
          continue
# Will buff
        if b < bs:
          ad += B
          hd -= ak
          b += 1
          continue
# Just attack
        hk -= ad
        hd -= ak
      if hk <= 0:
        res = min(res, n)

  if res >= INF:
    res = 'IMPOSSIBLE'
  print 'Case #{}: {}'.format(_t, res)
