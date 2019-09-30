n = int(input())
a, t = 0, 0
for _ in range(n):
  s = input()
  t += s.count("R")
  a += s.count("B")
if t == a:
  print("DRAW")
elif t > a:
  print("TAKAHASHI")
else:
  print("AOKI")