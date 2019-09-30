MOD = 10**9 + 7
N, M = map(int, input().split())
S = [[N+1]*(N+1) for i in [0,1,2]]
T = [[0]*(N+1) for i in [0,1,2]]

C = [0]*(N+1)
for i in range(M):
    l, r, x = map(int, input().split())
    if r-l < x-1:
        print(0)
        exit(0)
    S[x-1][r] = min(S[x-1][r], l)
    T[x-1][r] = max(T[x-1][r], l)
    C[r] = 1

S0, S1, S2 = S
T0, T1, T2 = T

ok = 1
for i in range(N+1):
    if not T2[i] < S1[i] or not T1[i] < S0[i]:
        ok = 0
        break

if not ok:
    print(0)
    exit(0)

RM = [N+1]*(N+1); GM = [N+1]*(N+1)
for i in range(N-1, -1, -1):
    RM[i] = min(RM[i+1], S1[i+1])
    GM[i] = min(GM[i+1], S0[i+1])


X = {(0, 0): 3}
D = [0]*(N+1); D[0] = 6
B = [{} for i in range(N+1)]
B[0][0] = 3
bb = 0
for b in range(1, N):
    t2 = T2[b+1]; s1 = S1[b+1]; t1 = T1[b+1]; s0 = S0[b+1]

    rm = RM[b]
    gm = GM[b]
    if t1 <= b < gm:
        F = B[b]
        for z in range(t2, min(rm, b)):
            v = D[z] % MOD
            if v:
                F[z] = v; D[z] += v; D[b] += v
    if C[b+1]:
        for g in range(bb, min(t1, b)):
            for r, v in B[g].items():
                D[r] -= v; D[g] -= v
            B[g] = None
        bb = max(t1, bb)
        for g in range(bb, b):
            for r, v in B[g].items():
                if not t2 <= r < s1:
                    D[r] -= v; D[g] -= v
            B[g] = {r: v for r, v in B[g].items() if t2 <= r < s1}
ans = 0
for b in range(bb, N+1):
    if B[b]:
        ans += sum(B[b].values())
print(ans % MOD)