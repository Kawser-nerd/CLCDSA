import sys
from fractions import gcd


with open("in.txt", "r") as f:
 with open("out.txt", "w") as fout:
  n = int(f.readline())
  for i in range(n):
    line = f.readline()
    p,q = map(int,line.strip().split('/'))
    x = gcd(p,q)
    p /= x
    q /= x
    k, ss = 0, 1
    res = ""
    while k<41 and ss*p % q != 0:
      k += 1
      ss *= 2
      if ss*p >= q and res == "":
        res = k
    if k == 41:
      res = "impossible"
    print >> fout, "Case #%d: %s" % (i+1, res)



