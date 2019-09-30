from itertools import accumulate

n, m = map(int, input().split())
imos = [0 for _ in range(m + 1)]
total = 0
for i in range(n):
  l, r, s = map(int, input().split())
  imos[l - 1] += s
  imos[r] -= s
  total += s
imos = list(accumulate(imos[:-1]))
print(total - min(imos))