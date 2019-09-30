def inpl(): return [int(i) for i in input().split()]
def hmd(a, b):
    ctr = -1
    while H[ctr+1][a] < b:
        ctr += 1
    vn = H[ctr][a]
    if (vn == b and ctr == 0) or ctr == -1:
        return 1
    return 2**ctr + hmd(vn,b)
N = int(input())
x = inpl() + [10**10]
L = int(input())
H = []
G = [N-1]*N
b = 0
for a in range(N):
    while x[b+1] - x[a] <= L:
        if b == N-1:
            break
        b += 1
    G[a] = b
H.append(G)
while G[0] != N-1:
    G = [G[i] for i in G]
    H.append(G)
H.append([10**10]*N)
Q = int(input())
for _ in range(Q):
    a, b = sorted(inpl())
    print(hmd(a-1,b-1))