from functools import *

inf = open('B-large.in')
ouf = open('B-large.out', 'w')
input = lambda: inf.readline().strip()
print = partial(print, file = ouf)


def solve():
    r, c, n = map(int, input().split())
    if r > c:
        r, c = c, r
    if n <= (r * c) // 2 + (r * c) % 2:
        print(0)
        return
    free = r * c - n
    cur = (r - 1) * c + (c - 1) * r
    if r == 1:
        if c % 2 == 0:
            ways = [[2] * (c // 2 - 1) + [1]]
        else:
            ways = [[2] * (c // 2), [2] * (c // 2 - 1) + [1, 1]]
    elif r * c % 2 == 0:
        ways = [[4] * ((r - 2) * (c - 2) // 2) + [3] * (r - 2 + c - 2) + [2, 2]]
    else:
        ways = [
            [4] * ((r - 2) * (c - 2) // 2 + 1) + [3] * (r - 3 + c - 3) + [2] * 4,
            [4] * ((r - 2) * (c - 2) // 2) + [3] * (r - 1 + c - 1),
        ]
    print(cur - max(sum(way[:free]) for way in ways))
    
    
tests = int(input())
for z in range(tests):
    print("Case #{}: ".format(z + 1), end = '')
    solve()

ouf.close()