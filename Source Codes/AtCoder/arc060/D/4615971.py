from collections import Counter
*W, = map(ord, input())
N = len(W)

C = Counter(W)
if len(C) == 1:
    print(N)
    print(1)
    exit(0)

def z_algo(S):
    A = [0]*N
    i = 1; j = 0
    A[0] = l = len(S)
    while i < l:
        while i+j < l and S[j] == S[i+j]:
            j += 1
        A[i] = j
        if not j:
            i += 1
            continue
        k = 1
        while l-i > k < j - A[k]:
            A[i+k] = A[k]
            k += 1
        i += k; j -= k
    return A

def calc(W):
    Z = z_algo(W)
    G = [0]*N
    for i in range(N):
        G[i] = 1
    for p in range(1, N):
        if not G[p-1]:
            continue
        for k in range(2, Z[p]//p+2):
            G[k*p-1] = 0
    return G
G0 = calc(W)
W.reverse()
G1 = calc(W)

if G0[N-1]:
    print(1)
    print(1)
    exit(0)

print(2)
print(sum(p and q for p, q in zip(G0[:-1], reversed(G1[:-1]))))