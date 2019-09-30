N, K = map(int, input().split())
mod = 10**9+7

# ?? & ????
factorial = [1]
inverse = [1]
for i in range(1, N+K+2):
    factorial.append(factorial[-1] * i % mod)
    inverse.append(pow(factorial[-1], mod-2, mod))


# ???????
def nCr(n, r):
    if n < r or r < 0:
        return 0
    elif r == 0:
        return 1
    return factorial[n] * inverse[r] * inverse[n - r] % mod


if N <= K:
    print(nCr(N, K%N) % mod)
else:
    print(nCr(N+K-1, K) % mod)