N, K = map(int, input().split())
data = [0]*(N+1)
def get(k):
    s = 0
    while k:
        s += data[k]
        k -= k & -k
    return s
def add(k, x):
    while k <= N:
        data[k] += x
        k += k & -k
def lower_bound(w):
    i = 0; s = 0
    k = 2**(N.bit_length()-1)
    while k > 0:
        if i + k <= N and data[i + k] < w:
            w -= data[i + k]
            i += k
        k >>= 1
    return i+1

a = 1
res = []
for i in range(N):
    m = (N-i)*a // K
    res.append(m)
    a = ((N-i)*a) % K
    add(i+1, 1)
idx = N-1
while res[idx] == 0:
    res[idx] = N-1-idx
    idx -= 1
res[idx] -= 1

ans = []
for i in res:
    idx = lower_bound(i+1)
    add(idx, -1)
    ans.append(idx)
print(*ans, sep='\n')