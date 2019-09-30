def solve(N, ABCs, Q, K, XYs):
    path = [[] for _ in range(N + 1)]
    for (a, b, c) in ABCs:
        path[a].append((b, c))
        path[b].append((a, c))

    dst = [0 for _ in range(N + 1)]

    q = [K]
    while len(q):
        index = q.pop()
        for n, w in path[index]:
            if dst[n] == 0:
                dst[n] = dst[index] + w
                q.append(n)
    ans = []
    for x, y in XYs:
        ans.append(str(dst[x] + dst[y]))
    return "\n".join(ans)

if __name__ == "__main__":
    N = int(input())
    ABCs = [tuple(map(int, input().split(" "))) for _ in range(N - 1)]
    Q, K = tuple(map(int, input().split(" ")))
    XYs = [tuple(map(int, input().split(" "))) for _ in range(Q)]
    print(solve(N, ABCs, Q, K, XYs))