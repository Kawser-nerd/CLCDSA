import sys
from collections import deque

mod = 10**9 + 7
inf = 1<<30

def solve():
    H, W, K = map(int, sys.stdin.readline().split())

    A = [[False]*W for i in range(H)]
    si = sj = -1

    for i in range(H):
        ai = sys.stdin.readline().rstrip()

        for j in range(W):
            if ai[j] == 'S':
                si = i
                sj = j
                A[i][j] = True
            elif ai[j] == '.':
                A[i][j] = True

    ans = bfs(H, W, K, A, si, sj)

    print(ans)

def bfs(H, W, K, A, si, sj):
    dx = (1, 0, -1, 0,)
    dy = (0, 1, 0, -1,)

    min_step = inf

    visited = [[False]*W for i in range(H)]
    visited[si][sj] = True
    nxts = deque([(si, sj, 0)])

    while nxts:
        r, c, d = nxts.popleft()

        min_step = min(min_step, r, H - 1 - r, c, W - 1 - c)

        if min_step == 0:
            return 1

        if d + 1 > K:
            continue

        for k in range(len(dx)):
            nr = r + dy[k]
            nc = c + dx[k]

            if 0 <= nr < H and 0 < nc < W:
                if A[nr][nc] and not visited[nr][nc]:
                    visited[nr][nc] = True
                    nxts.append((nr, nc, d + 1))

    ans = (min_step + K - 1) // K + 1

    return ans

if __name__ == '__main__':
    solve()