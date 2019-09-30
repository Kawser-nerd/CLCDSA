from itertools import permutations
import heapq

INF = 100000 * 200 * 10

def warshall(N, ABCs):
    dists = [[INF for _ in range(N)] for __ in range(N)]
    for i in range(N):
        dists[i][i] = 0

    for a, b, c in ABCs:
        dists[a - 1][b - 1] = c
        dists[b - 1][a - 1] = c

    for s in range(N):
        for e in range(N):
            for i in range(N):
                dists[s][e] = min(dists[s][e], dists[s][i] + dists[i][e])
    return dists


def dijkstra(s, e, N, ABCs):
    adjlist = [[] for _ in range(N)]
    for a, b, c in ABCs:
        adjlist[a - 1].append((b, c))
        adjlist[b - 1].append((a, c))

    q = [(0, s)]
    while len(q):
        d, i = heapq.heappop(q)
        if i == e:
            return d
        for nexti, nextd in adjlist[i - 1]:
            heapq.heappush(q, (d + nextd, nexti))
    return None


def dense_dijkstra(s, e, N, ABCs):
    distsmap = [[-1 for _ in range(N)] for __ in range(N)]
    for a, b, c in ABCs:
        distsmap[a - 1][b - 1] = c
        distsmap[b - 1][a - 1] = c

    dists = [INF for _ in range(N)]
    visited = [False for _ in range(N)]
    dists[s - 1] = 0

    while True:
        minW, index = min([(dists[i], i) for i in range(N) if not visited[i]])
        visited[index] = True
        if minW == INF:
            return -1
        if index + 1 == e:
            return minW
        for rindex, w in enumerate(distsmap[index]):
            if w == -1:
                continue
            dists[rindex] = min(dists[rindex], minW + w)


def solve(N, M, R, Rs, ABCs):
    dists = [[-1 for _ in range(N)] for __ in range(N)]
    ans = INF
    for way in permutations(Rs):
        tans = 0
        for s, e in zip(way, way[1:]):
            if dists[s - 1][e - 1] == -1:
                d = dense_dijkstra(s, e, N, ABCs)
                dists[s - 1][e - 1] = d
                dists[e - 1][s - 1] = d
            else:
                d = dists[s - 1][e - 1]
            tans += d
        ans = min(ans, tans)

    return ans

if __name__ == "__main__":
    N, M, R = tuple(map(int, input().split(" ")))
    Rs = list(map(int, input().split(" ")))
    ABCs = [tuple(map(int, input().split(" "))) for _ in range(M)]
    print(solve(N, M, R, Rs, ABCs))