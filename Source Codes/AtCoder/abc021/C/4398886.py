#!/usr/bin/env python3

from collections import deque

def main():
    n = int(input())
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    m = int(input())
    adj_mat = [[False for j in range(n)] for i in range(n)]
    for i in range(m):
        x, y = map(int, input().split())
        adj_mat[x - 1][y - 1] = True
        adj_mat[y - 1][x - 1] = True

    queued = [False for i in range(n)]
    shortest_paths = [0 for i in range(n)]
    shortest_dist = [10 ** 9 for i in range(n)]
    q = deque([a])
    queued[a] = True
    shortest_paths[a] = 1
    shortest_dist[a] = 0
    while q:
        st = q.popleft()
        for i in range(n):
            if adj_mat[st][i]:
                if not queued[i]:
                    q.append(i)
                    queued[i] = True
                shortest_dist[i] = min(shortest_dist[i], shortest_dist[st] + 1)
                if shortest_dist[i] == shortest_dist[st] + 1:
                    shortest_paths[i] += shortest_paths[st]
                    shortest_paths[i] %= 10 ** 9 + 7
    print(shortest_paths[b])

main()