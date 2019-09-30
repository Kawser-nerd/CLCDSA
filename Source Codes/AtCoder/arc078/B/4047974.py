N = int(input())
edge = [[]*N for _ in range(N)]

for _ in range(N-1):
    go,to = map(int,input().split())
    go -= 1
    to -= 1
    edge[go].append(to)
    edge[to].append(go)
    
from collections import deque
que = deque(maxlen=N)
que.append([0,0])
dist0 = [None]*N
distn = [None]*N
while(que):
    v = que.popleft()
    c = v[0]
    d = v[1]
    for i in edge[c]:
        if dist0[i] is None:
            dist0[i] = d + 1
            que.append([i,d+1])
que.append([N-1,0])
while(que):
    v = que.popleft()
    c = v[0]
    d = v[1]
    for i in edge[c]:
        if distn[i] is None:
            distn[i] = d + 1
            que.append([i,d+1])
w = b = 0
for d1,dn in zip(dist0,distn):
    if d1<=dn:
        b += 1
    else:
        w += 1
print('Fennec' if b-w > 0 else 'Snuke')