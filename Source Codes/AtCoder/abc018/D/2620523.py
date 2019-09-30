from itertools import combinations
n, m, p, q, r = map(int, input().split())
combos = list(combinations(list(range(0, n)), p))
ans = 0
# ??????????
info = []
for i in range(n):
  info.append([0]*m)

for i in range(r):
  a, b, c = map(int, input().split())
  info[a-1][b-1] = c

combos = list(combinations(list(range(0, n)), p))

for combo in combos:
  temp = [0]*m
  for i in range(m):
    for w in combo:
      temp[i] += info[w][i]
  temp = sorted(temp, reverse=True)
  ans = max(ans, sum(temp[:q]))

print(ans)