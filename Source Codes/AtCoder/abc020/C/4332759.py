import heapq

h, w, t = map(int, input().split())
array = [input() for _ in range(h)]

# ?????????????
S = [0, 0]
G = [0, 0]
for i in range(h):
    for j in range(w):
        if array[i][j] == "S":
            S = (i, j)
        if array[i][j] == "G":
            G = (i, j)


def compare_cost(x):
    # ?????????????????
    v = [[False for _ in range(w)] for _ in range(h)]
    q = [(0, S)]
    while q:
        c, (i, j) = heapq.heappop(q)
        for di, dj in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
            ni = i + di
            nj = j + dj
            if (not 0<= ni < h) or (not 0 <= nj < w):
                # ?????????????
                continue
            if v[ni][nj]:
                # ??????????
                continue
            # sij ????????????
            v[ni][nj] = True
            # ??????
            nc = c + (x if array[ni][nj]=="#" else 1)
            if (ni, nj) == G:
                # ?????????????????????? t ??????? True ???
                return nc <= t
            heapq.heappush(q, (nc, (ni, nj)))


# ????
lo = 1
hi = t
while lo + 1 < hi:
    mid = (lo + hi) // 2
    if compare_cost(mid):
        lo = mid
    else:
        hi = mid

print(lo)