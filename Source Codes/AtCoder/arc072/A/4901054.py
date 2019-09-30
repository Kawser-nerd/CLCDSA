n = int(input())

A = list(map(int, input().split()))


N = A[:]
ncount = 0
if N[0] >= 0:
    ncount += abs(N[0]) + 1
    N[0] = -1
for i in range(1, n):
    N[i] +=  N[i-1]
    if i % 2 == 1:
        if N[i] <= 0:
            ncount += abs(N[i]) + 1
            N[i] = 1
    else:
        if N[i] >= 0:
            ncount += abs(N[i]) + 1
            N[i] = -1

P = A[:]
pcount = 0
if P[0] <= 0:
    pcount += abs(P[0]) + 1
    P[0] = 1
for i in range(1, n):
    P[i] +=  P[i-1]
    if i % 2 == 0:
        if P[i] <= 0:
            pcount += abs(P[i]) + 1
            P[i] = 1
    else:
        if P[i] >= 0:
            pcount += abs(P[i]) + 1
            P[i] = -1



print(min(ncount, pcount))