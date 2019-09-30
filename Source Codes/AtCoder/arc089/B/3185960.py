import sys
from itertools import accumulate


N, K = map(int, input().split())
grid = [[0]*(K*2+1) for _ in [0]*(K*2+1)]
for x, y, c in (l.split() for l in sys.stdin):
    x, y = int(x), int(y)
    if c=="B": x+=K
    grid[y%(K*2)+1][x%(K*2)+1] += 1
for y, (up, cur) in enumerate(zip(grid, grid[1:]), start=1):
    grid[y] = [0]+[n1+n2 for n1, n2 in zip(up[1:], accumulate(cur[1:]))]
ans = 0
total = grid[-1][-1]
for y in range(K+1):
    r1, r2 = grid[y][-1], grid[y+K][-1]
    for x, (up_l, up_r, down_l, down_r, d1, d2) in\
     enumerate(zip(grid[y], grid[y][K:], grid[y+K], grid[y+K][K:], grid[-1], grid[-1][K:])):
        v = down_r - down_l - up_r + up_l
        v += total-d2-r2+down_r
        v += d1 - down_l
        v += r1 - up_r
        v += up_l
        if v < N-v:
            v = N-v

        if ans < v:
            ans = v
print(ans)