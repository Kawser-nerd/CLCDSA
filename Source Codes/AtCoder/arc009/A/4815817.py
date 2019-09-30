N = int(input())
ab = [[int(_) for _ in input().split()] for i in range(N)]

import math

result = math.floor(sum(a * b for a, b in ab) * 1.05)
print(result)