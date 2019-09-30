from itertools import chain
  
n = int(input())
ts = list(map(int, input().split()))
vs = list(map(int, input().split()))
  
va = list(chain.from_iterable([v] * (2 * t) for t, v in zip(ts, vs)))
va = [min(v1, v2) for v1, v2 in zip([0] + va, va + [0])]
lt = len(va)
  
pv = 0
for ct in range(1, lt):
    va[ct] = pv = min(va[ct], pv + 0.5)
  
pv = 0
for ct in range(lt - 1, 0, -1):
    va[ct] = pv = min(va[ct], pv + 0.5)
  
print(sum((v1 + v2) / 4 for v1, v2 in zip(va, va[1:])))