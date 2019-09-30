import sys
from collections import deque

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
        print(k_dist[x-1] + k_dist[y-1])


if __name__ == '__main__':
    main()