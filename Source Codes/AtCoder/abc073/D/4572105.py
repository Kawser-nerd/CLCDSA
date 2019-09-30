def solve():
        from itertools import permutations
        N, M, R = map(int, input().split())
        rs = map(lambda x: int(x) - 1, input().split())
        dist, ans = [[float("inf") for _ in range(N)] for _ in range(N)], float("inf")
        for _ in range(M):
            v1, v2, d = map(int, input().split())
            dist[v1-1][v2-1] = dist[v2-1][v1-1] = d
        for i in range(N):
            dist[i][i] = 0
        for k in range(N):
            for i in range(N):
                for j in range(N):
                    if dist[i][j] > dist[i][k] + dist[k][j]:
                        dist[i][j] = dist[i][k] + dist[k][j]
        for r in permutations(rs):
            t = 0
            for i in range(R - 1):
                t += dist[r[i]][r[i + 1]]
            ans = min(t, ans)
        print(ans)

if __name__ == "__main__":
    solve()