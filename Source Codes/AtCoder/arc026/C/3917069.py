N, L = map(int, input().split())

N0 = 2**(L).bit_length()
INF = 10**15
data = [INF]*(2*N0)
# a_k ??? x ???
def update(k, x):
    k += N0-1
    data[k] = x
    while k >= 0:
        k = (k - 1) // 2
        data[k] = min(data[2*k+1], data[2*k+2])
# ??[l, r)????
def query(l, r):
    L = l + N0; R = r + N0
    s = INF
    while L < R:
        if R & 1:
            R -= 1
            s = min(s, data[R-1])

        if L & 1:
            s = min(s, data[L-1])
            L += 1
        L >>= 1; R >>= 1
    return s

P = [list(map(int, input().split())) for i in range(N)]
P.sort(key=lambda x: x[1])

V = [INF]*(L+1)
V[0] = 0
update(0, 0)
for l, r, c in P:
    v = query(l, r)
    if v + c <= V[r]:
        V[r] = v + c
        update(r, v + c)
print(V[L])