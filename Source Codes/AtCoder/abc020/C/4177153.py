import heapq

h, w, t = [int(x) for x in input().split()]
s = [input().strip() for _ in range(h)]

for i, si in enumerate(s):
    for j, sij in enumerate(si):
        if sij == "S":
            S = i, j
        elif sij == "G":
            G = i, j


def f(x):
    v = [[False for _ in range(w)] for __ in range(h)]
    q = [(0, S)]
    while q:
        c, (i, j) = heapq.heappop(q)
        for di, dj in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
            ni, nj = i + di, j + dj
            if not 0 <= ni < h or not 0 <= nj < w:
                continue
            if v[ni][nj]:
                continue
            v[ni][nj] = True
            nc = c + (x if s[ni][nj] == "#" else 1)
            if (ni, nj) == G:
                return nc <= t
            heapq.heappush(q, (nc, (ni, nj)))
    return False


lo = 1
hi = t
while lo + 1 < hi:
    mid = (lo + hi) // 2
    if f(mid):
        lo = mid
    else:
        hi = mid

print(lo)