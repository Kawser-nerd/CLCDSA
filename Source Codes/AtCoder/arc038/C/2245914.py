# seishin.py
N = int(input())
C = [0]*N; A = [0]*N
begin = []
for i in range(1, N):
    C[i], A[i] = map(int, input().split())
    A[i] &= 1

N0 = 2**(N-1).bit_length()
data = [-1]*(N0*2)

# G[x] = k ??????
def update(k, x):
    k += N0 - 1
    data[k] = x
    while k:
        k = (k - 1) // 2
        data[k] = min(data[2*k+1], data[2*k+2])

# G[j], ..., G[i-1]??????????greedy?????
def query(j):
    k = 0; l = 0; r = N0
    if j <= data[k]:
        return l
    while k < N0-1:
        # G[j], ..., G[i-1] ???????? (l+r)/2 ?????
        if data[2*k+1] < j:
            r = (l + r) // 2
            k = 2*k + 1
        else:
            # (l+r)/2 ??
            l = (l + r) // 2
            k = 2*k + 2
    return l

# G[0] = 0
update(0, 0)
ans = 0
for i in range(1, N):
    # G[i - C[i]], ..., G[i-1] ?????????greedy?k????
    k = query(i - C[i])
    update(k, i)
    if A[i]:
        # A[i] ???????XOR
        ans ^= k
print('First' if ans else 'Second')