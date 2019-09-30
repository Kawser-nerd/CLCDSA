from math import *

n, k = map(int, input().split())
a = input()

ans = ceil((n-1)/(k-1))
print(ans)