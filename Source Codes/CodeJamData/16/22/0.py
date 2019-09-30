T = int(raw_input())

bestc = None
bestj = None
bestd = None

def val(c):
    return ord(c) - 48

pow10 = [10**i for i in range(20)]

def search(i, delta, s, t, cc, cj):
    #print i, delta, s, t, cc, cj
    if i == len(s):
        global bestd, bestc, bestj
        if bestd is None or (abs(delta), cc, cj) < (bestd, bestc, bestj):
            bestd = abs(delta)
            bestc = cc
            bestj = cj
        return

    if s[i] == '?' or t[i] == '?':
        p10 = len(s) - 1 - i

        max = 0
        min = 0
        if s[i] == '?' and t[i] == '?':
            max = 9
            min = -9
        elif s[i] == '?':
            max = 9 - val(t[i])
            min = -val(t[i])
        elif t[i] == '?':
            max = val(s[i])
            min = val(s[i]) - 9

        def attempt(amt):
            if amt > max:
                amt = max
            if amt < min:
                amt = min
            if s[i] == '?' and t[i] == '?':
                if amt < 0:
                    ncc = cc*10
                    ncj = cj*10 - amt
                else:
                    ncc = cc*10 + amt
                    ncj = cj*10
            elif s[i] == '?':
                ncc = cc*10 + val(t[i]) + amt
                ncj = cj*10 + val(t[i])
            elif t[i] == '?':
                ncc = cc*10 + val(s[i])
                ncj = cj*10 + val(s[i]) - amt
            search(i+1, delta + amt*pow10[p10], s, t, ncc, ncj)

        if delta < 0:
            div = -(-delta // pow10[p10])
            attempt(-div)
            attempt(-div + 1)
        else:
            div = delta // pow10[p10]
            attempt(-div)
            attempt(-div - 1)
    else:
        cc = cc*10 + val(s[i])
        cj = cj*10 + val(t[i])
        search(i+1, delta, s, t, cc, cj)

for tn in range(T):
  s, t = raw_input().split()
  N = len(s)
  delta = 0
  for i in range(N):
     p10 = N-1-i
     if s[i] != '?' and t[i] != '?':
         delta += (ord(s[i]) - ord(t[i])) * (10 ** p10)

  bestd = None
  search(0, delta, s, t, 0, 0)
  c = str(bestc)
  j = str(bestj)
  print 'Case #%d: %s %s' % (tn+1, c.zfill(N), j.zfill(N))
