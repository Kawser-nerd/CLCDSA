from collections import defaultdict

h, w, n = map(int, input().split())

abd = defaultdict(int)
for _ in range(n):
  a, b = map(int, input().split())
  abd[(a, b)] += 1
  abd[(a, b-1)] += 1
  abd[(a, b-2)] += 1
  abd[(a-1, b)] += 1
  abd[(a-1, b-1)] += 1
  abd[(a-1, b-2)] += 1
  abd[(a-2, b)] += 1
  abd[(a-2, b-1)] += 1
  abd[(a-2, b-2)] += 1

suma = [0 for _ in range(10)]
for a, b in abd.keys():
  if 0 < a < h-1 and 0 < b < w-1:
    suma[abd[(a,b)]] += 1
suma[0] = (h - 2) * (w - 2) - sum(suma)
print(*suma, sep='\n')