from functools import *

inf = open('B-large.in')
ouf = open('output.txt', 'w')
input = lambda: inf.readline().strip()
print = partial(print, file = ouf)


def solve():
    n, p = map(int, input().split())
    y = max(min(2 ** q - 2, 2 ** n - 1) for q in range(1, n + 2) if 2 ** n - 2 ** (n - q + 1) < p)
    z = max(2 ** n - 2 ** q for q in range(0, n + 1) if 2 ** (n - q) - 1 < p)
    print(y, z)
    
    
tests = int(input())
for z in range(tests):
    print("Case #{}: ".format(z + 1), end = '')
    solve()

ouf.close()