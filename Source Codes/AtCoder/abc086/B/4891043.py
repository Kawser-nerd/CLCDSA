import math

a, b = [_ for _ in input().split()]
n = int(a + b)

m = int(math.sqrt(n))
print('Yes' if m*m == n else 'No')