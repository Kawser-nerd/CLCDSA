from collections import defaultdict
import sys
sys.setrecursionlimit(10 ** 6)


def dfs(i, g, dist):
    for node in g[i]:
        if dist[node] is None:
            dist[node] = dist[i] + 1
            dfs(node, g, dist)


def main():
    g = defaultdict(list)
    N = int(input())
    for _ in range(N - 1):
        A, B = map(int, input().split())
        g[A].append(B)
        g[B].append(A)

    dist = [None] * (N + 1)
    dist[0] = -1
    dist[1] = 0
    # from 1
    dfs(1, g, dist)
    ans1 = dist.index(max(dist))

    # from ans1
    dist = [None] * (N + 1)
    dist[0] = -1
    dist[ans1] = 0
    dfs(ans1, g, dist)
    ans2 = dist.index(max(dist))

    print(ans1, ans2)


if __name__ == '__main__':
    main()