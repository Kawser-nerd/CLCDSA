#!/usr/bin/env python3

# Google Code Jam Round 1B 2017
# Problem C. Pony Express
# Solution in Python
# By Smithers

def dijkstra(n, d, i):
    done = [False] * n
    result = [-1] * n
    result[i] = 0
    while i >= 0:
        done[i] = True
        for j in range(n):
            if d[i][j] > 0 and (result[j] < 0 or result[i] + d[i][j] < result[j]):
                result[j] = result[i] + d[i][j]
        i = -1
        for j in range(n):
            if not done[j] and result[j] > 0 and (i < 0 or result[j] < result[i]):
                i = j
    return result

for x in range(1, int(input()) + 1):
    n, q = map(int, input().split())
    
    e = []
    s = []
    for _ in range(n):
        e_, s_ = map(int, input().split())
        e.append(e_)
        s.append(s_)
    d = []
    for _ in range(n):
        d.append(list(map(int, input().split())))
    
    d2 = []
    for i in range(n):
        row = dijkstra(n, d, i)
        d2.append([entry / s[i] if 0 < entry <= e[i] else -1 for entry in row])
    
    y = []
    for i in range(q):
        u, v = map(int, input().split())
        row = dijkstra(n, d2, u - 1)
        y.append(row[v - 1])
    
    print('Case #' + str(x) + ':', *y)
