from collections import deque
N, M = map(int, input().split())
G0 = [set([i]) for i in range(N)]

A = set(range(N))

for i in range(M):
    a, b = map(int, input().split())
    G0[a-1].add(b-1)
    G0[b-1].add(a-1)

G = [A - g for g in G0]

b = 1 << (N//2)
c = [-1]*N
for i in range(N):
    if c[i] != -1:
        continue
    p = 0; s = 0
    que = deque([i])
    c[i] = 0
    while que:
        v = que.popleft()
        s += 1
        if c[v] == 0:
            p += 1
        for w in G[v]:
            if c[w] == -1:
                c[w] = c[v]^1
                que.append(w)
            elif c[w] == c[v]:
                print(-1)
                exit(0)
    b = (b >> p) | (b >> (s-p))

p = N//2 - ((b & -b).bit_length()-1)
q = N - p
print(p*(p-1)//2 + q*(q-1)//2)