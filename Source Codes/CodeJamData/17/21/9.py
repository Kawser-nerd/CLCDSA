from sys import stdin


T = int(stdin.readline())
for t in range(T):
  D, N = (int(x) for x in stdin.readline().split())
  m = None
  for n in range(N):
    K, S = (int(x) for x in stdin.readline().split())
    l = float(D - K) / S
    if m is None or m < l:
      m = l
  s = D / m
  print("Case #%d: %.8f" % (t + 1, s))
