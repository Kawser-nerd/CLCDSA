# https://beta.atcoder.jp/contests/agc014/submissions/1268295
from collections import deque

dr = (0, 1, 0, -1)
dc = (1, 0, -1, 0)


def solve():
    H, W, K = map(int, input().split())
    a = [[False for _ in range(W)] for _ in range(H)]

    sy, sx = -1, -1
    for r in range(H):
        s = input()
        for c, x in enumerate(s):
            if x == '.':
                a[r][c] = True
            elif x == 'S':
                a[r][c] = True
                sy, sx = r, c

    visited = [[False for _ in range(W)] for _ in range(H)]
    visited[sy][sx] = True

    t = max(H, W)
    q = deque([(sy, sx, 0)])
    while q:
        r, c, k = q.popleft()

        t = min(t, r, H - 1 - r, c, W - 1 - c)
        # print(t)
        if t == 0:
            print(1)
            return

        for d_i in range(4):
            nr, nc = r + dr[d_i], c + dc[d_i]
            if 0 <= nr < H and 0 <= nc < W and a[nr][nc] and not visited[nr][nc] and k + 1 <= K:
                visited[nr][nc] = True
                q.append((nr, nc, k + 1))

    ans = 1 + (t + K - 1) // K

    print(ans)


if __name__ == '__main__':
    solve()