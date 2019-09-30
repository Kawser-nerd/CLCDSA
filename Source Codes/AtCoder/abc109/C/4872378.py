import fractions
from functools import reduce

N, X = map(int, input().split())
xi = list(map(int, input().split()))

xi.append(X)
xi.sort()

diffs = []
for i in range(N):
    diffs.append(xi[i+1] - xi[i])

ans = reduce(fractions.gcd, diffs)
print(ans)