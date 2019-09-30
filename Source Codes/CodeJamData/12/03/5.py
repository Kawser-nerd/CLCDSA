from sys import stdin

T = int(next(stdin))
for t in range(1,T+1):
  A,B = [int(S) for S in next(stdin).split()]
  Bl = list(str(B))
  count = 0
  for i in range(A,B):
    l = list(str(i))
    ls = l[:]
    used = {}
    for j in range(len(l)):
      l = l[1:]+l[:1]
      if l <= ls or l > Bl: continue
      lstr = "".join(l)
      if lstr in used: continue
      used[lstr] = True
      count += 1
  print "Case #%d:"%(t),count
