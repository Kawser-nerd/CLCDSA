import heapq

def add_neighbours(H, N, M, floors, ceils, q, i, j, time):
    for k, l in (i, j - 1), (i, j + 1), (i - 1, j), (i + 1, j):
        if 0 <= k < N and 0 <= l < M:
            if ceils[k][l] - max(floors[i][j], floors[k][l]) >= 50 and \
                    ceils[i][j] - floors[k][l] >= 50:
                if time == 0 and ceils[k][l] - H >= 50:
                    dtime = 0
                else:
                    water = H - 10 * time
                    mini = min(water, ceils[k][l] - 50)
                    dtime = (water - mini) / 10
                    if mini - floors[i][j] >= 20:
                        dtime += 1
                    else:
                        dtime += 10
                heapq.heappush(q, (time + dtime, k, l))

def solve(H, N, M, floors, ceils):
#    print(H, N, M, floors, ceils)
    start = 0, 0
    finish = N - 1, M - 1
    d = {start : 0}
    q = []
    add_neighbours(H, N, M, floors, ceils, q, 0, 0, 0)
    while q:
#        print(q)
        time, i, j = heapq.heappop(q)
        if (i, j) not in d:
            d[i, j] = time
            add_neighbours(H, N, M, floors, ceils, q, i, j, time)
    return d[finish]

T = int(input ())
for i in range(1, T + 1):
    H, N, M = map(int, input().split())
    ceils  = [list(map(int, input().split())) for i in range(N)]
    floors = [list(map(int, input().split())) for i in range(N)]
    print("Case #%d: %s" % (i, solve(H, N, M, floors, ceils)))

