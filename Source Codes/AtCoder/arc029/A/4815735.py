N = int(input())
t = [int(input()) for i in range(N)]

ans = sum(t)

for i in range(2**N):
  g1, g2 = 0,0 #??????????
  for j in range(N):
    if (i >> j) & 1:
      g1 += t[j]
    else:
      g2 += t[j]
  ans = min(ans, max(g1, g2))
print(ans)