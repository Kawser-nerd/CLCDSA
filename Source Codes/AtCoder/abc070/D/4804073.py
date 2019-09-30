import sys
from collections import deque

def dfs(start, dest, pre, d):
    if d[start][dest] > 0:
        return d[start][dest]

    for i in range(len(d)):
        if d[start][i] > 0 and i != pre:
            c = dfs(i, dest, start, d)
            if c > 0:
                return d[start][i] + dfs(i, dest, start, d)

    return 0

def main():
    input = sys.stdin.readline
    N = int(input())
    
    d = [[] for _ in range(N)]
    for _ in range(N-1):
        a, b, c = map(int, input().split())
        a, b = a - 1, b - 1
        
        d[a].append((b, c))
        d[b].append((a, c))

    Q, K = map(int, input().split())
    K -= 1

    k_dist = [0 for _ in range(N)]
    start = deque()
    start.append(K)
    while len(start) > 0:
        s = start.popleft()
        for dest, cost in d[s]:
            if k_dist[dest] > 0:
                continue

            k_dist[dest] = k_dist[s] + cost
            start.append(dest)

    for _ in range(Q):
        x, y = map(int, input().split())
        x, y = x - 1, y - 1

        print(int(k_dist[x] + k_dist[y]))


if __name__ == '__main__':
    main()