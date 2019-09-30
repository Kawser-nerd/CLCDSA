N = int(input())
P = [list(map(int, input().split())) for i in range(N)]
MP = {tuple(p): i for i, p in enumerate(P)}

def cross(C, A, B):
    return (C[0] - A[0])*(C[1] - B[1]) - (C[1] - A[1])*(C[0] - B[0])

def convex_hull(P):
    P.sort()
    Q = []
    for p in P:
        while 1 < len(Q) and cross(Q[-2], Q[-1], p) >= 0:
            Q.pop()
        Q.append(p)
    k = len(Q)
    for p in reversed(P[:-1]):
        while k < len(Q) and cross(Q[-2], Q[-1], p) >= 0:
            Q.pop()
        Q.append(p)
    return Q

from math import atan2, pi

Q = convex_hull(P)[:-1]
K = len(Q)
ans = [0.]*N
for i in range(K):
    S = Q[i-1]; T = Q[i]; U = Q[(i+1)%K]
    X0 = T[0] - S[0]; X1 = U[0] - T[0]
    Y0 = T[1] - S[1]; Y1 = U[1] - T[1]
    ans[MP[tuple(Q[i])]] = atan2(X1*Y0 - X0*Y1, X0*X1 + Y0*Y1) / 2. / pi
print(*ans, sep='\n')