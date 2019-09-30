import fractions
from functools import reduce
from sys import stdin
N, X = [int(_) for _ in stdin.readline().rstrip().split()]
xs = [int(_) for _ in stdin.readline().rstrip().split()]
xs.sort()
diff = [xs[i] - xs[i-1] if i > 0 else abs(xs[i]-X) for i in range(N)]
gcd = reduce(fractions.gcd, diff)
print(gcd)