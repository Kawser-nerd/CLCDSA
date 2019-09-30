from heapq import heappush, heappop

t = int(input())

for i in range(t):
    print("Case #%d:" % (i + 1), end = " ")
    n, s = map(int, input().split())
    t = []
    for i in range(n):
        t.append(list(map(int, input().split())))
    def dist2(i, j):
        return (t[i][0] - t[j][0]) ** 2 + (t[i][1] - t[j][1]) ** 2 + (t[i][2] - t[j][2]) ** 2
    seen = [False] * n
    seen[0] = True
    maxd = 0
    closest = []
    for i in range(1, n):
        heappush(closest, (dist2(0, i), i))
    while True:
        dd, i = heappop(closest)
        if i == 1:
            if dd > maxd:
                maxd = dd
            break
        if seen[i]: continue
        seen[i] = True
        if dd > maxd:
            maxd = dd
        for j in range(n):
            if not seen[j]:
                heappush(closest, (dist2(i, j), j))
    print(maxd ** 0.5)
        
