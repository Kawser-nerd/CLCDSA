from heapq import heappop, heappush

N = int(input())
L = [[] for i in range(N + 1)]
Fd = [float("inf") for i in range(N + 1)]
Sd = [float("inf") for i in range(N + 1)]
Fd[1] = 0
Sd[N] = 0

for i in range(N - 1):
    a, b = list(map(int, input().split()))
    L[a].append(b)
    L[b].append(a)

Q = []
heappush(Q, 1)
while Q:
    n = heappop(Q)
    d = Fd[n]
    for x in L[n]:
        if Fd[x] == float("inf"):
            Fd[x] = d + 1
            heappush(Q, x)

Q = []
heappush(Q, N)
while Q:
    n = heappop(Q)
    d = Sd[n]
    for x in L[n]:
        if Sd[x] == float("inf"):
            Sd[x] = d + 1
            heappush(Q, x)

f = 0
s = 0
for i in range(1, N + 1):
    if Fd[i] <= Sd[i]:
        f += 1
    else:
        s += 1

if f > s:
    print("Fennec")
else:
    print("Snuke")