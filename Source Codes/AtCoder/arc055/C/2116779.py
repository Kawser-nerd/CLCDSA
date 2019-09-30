*S, = map(ord, input())

MOD = 10**9+7
base = 3
L = len(S)


data = [0]*(L+1)
for i in range(L):
    data[i+1] = (data[i]*base + S[i]) % MOD

def get(l, r):
    return (data[r] - data[l] * pw[r-l]) % MOD

pw = [0]*(L//2+1)
for i in range(L//2+1):
    pw[i] = pow(base, i, MOD)

def solve(i):
    R = L - i
    if S[i] != S[0] or S[i-1] != S[-1]:
        return 0

    left = 1; right = R
    while left+1 < right:
        mid = (left + right) // 2
        if get(0, mid) == get(i, i+mid):
            left = mid
        else:
            right = mid
    A = left

    T = R - A
    if get(i-T, i) != get(L-T, L):
        return 0

    left = T; right = R
    while left+1 < right:
        mid = (left + right) // 2
        if get(i-mid, i) == get(L-mid, L):
            left = mid
        else:
            right = mid
    C = left
    return A + C - R + 1
print(sum(map(solve, range(L//2+1, L-1))))