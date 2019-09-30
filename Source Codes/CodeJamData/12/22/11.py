from heapq import *

inf = open("B-large.in")
outf = open("B-large.out", "w")

numTests = int(inf.readline().rstrip())

def canMove(si, sj, di, dj, t):
    if not (0 <= di < N and 0 <= dj < M):
        return False
    for h in (H - t, F[si][sj], F[di][dj]):
        if C[di][dj] - h < 50:
            return False
    if C[si][sj] - F[di][dj] < 50:
        return False
    return True

def moveCost(si, sj, t):
    return (1 if H - t - F[si][sj] >= 20 else 10) * 10

def moves(i, j):
    for di in range(-1, 2):
        for dj in range(-1, 2):
            if abs(di) != abs(dj):
                yield i + di, j + dj

def getMinTime():
    best = [[-1] * M for _ in range(N)]
    best[0][0] = 0
    queue = [(0, 0)]
    heap = [(0, 0, 0)]
    while queue:
        [i, j], queue = queue[0], queue[1:]
        for di, dj in moves(i, j):
            if canMove(i, j, di, dj, 0) and best[di][dj] == -1:
                queue.append([di, dj])
                best[di][dj] = 0
                heap.append( (0, di, dj) )
    heapify(heap)
    while heap:
        t, i, j = heappop(heap)
        if t > best[i][j]:
            continue
        for di, dj in moves(i, j):
            if canMove(i, j, di, dj, t):
                realMoment = t
            elif canMove(i, j, di, dj, H + 1):
                realMoment = H - (C[di][dj] - 50)
            else:
                continue
            cost = moveCost(i, j, realMoment)
            if best[di][dj] == -1 or best[di][dj] > realMoment + cost:
                best[di][dj] = realMoment + cost
                heappush(heap, (realMoment + cost, di, dj))
    return best[N - 1][M - 1]

for test in range(numTests):
    H, N, M = map(int, inf.readline().split())
    C = []
    F = []
    for i in range(N):
        C.append(list(map(int, inf.readline().split())))
    for i in range(N):
        F.append(list(map(int, inf.readline().split())))
    print("Case #%d: %.2f" % (test + 1, getMinTime() / 10.0), file=outf)

