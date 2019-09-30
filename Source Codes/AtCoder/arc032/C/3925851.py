N = int(input())
P = []
for i in range(N):
    a, b = map(int, input().split())
    P.append((a, b, i))

L = 10**6
T = [(0, 1)]*(L+1)
R = [-1]*N

P.sort(key=lambda x: x[1], reverse=1)
que = []
prv = L
for a, b, j in P:
    for i in range(prv-1, b-1, -1):
        T[i] = max(T[i], T[i+1])
    c, k = T[b]
    R[j] = -k
    T[a] = max(T[a], (c+1, -j))
    prv = b
for i in range(prv-1, -1, -1):
    T[i] = max(T[i], T[i+1])

ans = []
v = -T[0][1]
while v != -1:
    ans.append(v+1)
    v = R[v]
print(len(ans))
print(*ans)