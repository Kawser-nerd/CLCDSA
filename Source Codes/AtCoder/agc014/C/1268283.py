import sys
from collections import deque

dx = (1, 0, -1, 0,)
dy = (0, 1, 0, -1,)

inf = 1<<60

def solve():
    h, w, k = map(int, sys.stdin.readline().split())

    si = -1
    sj = -1

    a = [[False]*w for i in range(h)]

    for i in range(h):
        s = sys.stdin.readline().rstrip()

        for j, ch in enumerate(s):
            if ch == '.':
                a[i][j] = True
            elif ch == 'S':
                a[i][j] = True
                si, sj = i, j

    visited = [[False]*w for i in range(h)]
    visited[si][sj] = True

    nxts = deque([(si, sj, 0)])

    ans = inf

    while nxts:
        i, j, d = nxts.popleft()

        ans = min(ans, i, h - 1 - i, j, w - 1 - j)

        for l in range(len(dx)):
            ni = i + dy[l]
            nj = j + dx[l]

            if 0 <= ni < h and 0 <= nj < w and not visited[ni][nj] and a[ni][nj] and d + 1 <= k:
                visited[ni][nj] = True
                nxts.append((ni, nj, d + 1))

    ans = (ans + k - 1) // k + 1

    print(ans)

if __name__ == '__main__':
    solve()