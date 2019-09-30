# -*- coding: utf-8 -*-
from collections import deque
def inpl(): return tuple(map(int, input().split()))

K = int(input())
visited = [False for _ in range(K)] 
dq = deque([(1, 1)]) # cost, mod

while True:
    c, m = dq.popleft()
    visited[m] = True
    if m == 0:
        print(c)
        break
    else:
        if not visited[(m*10)%K]:
            dq.appendleft((c, (m*10)%K))
        if not visited[(m+1)%K]:
            dq.append((c+1, (m+1)%K))