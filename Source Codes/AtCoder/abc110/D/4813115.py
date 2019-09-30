N, M = map(int, input().split())
# ?????
def factorization(N):
    prime = primelist(int(N**(1/2))+2)
    factor = [0 for i in range(int(N**(1/2)+2))]
    isprime = False
    for i in prime:
        while N % i == 0:
            N = N // i
            factor[i] += 1
    if sum(factor) == 0:
        isprime = True
    if N != 1:
        factor.append(1)
    return factor, isprime

# ??
def primelist(N):
    prime = [2]
    for i in range(3, N+1):
        flag = 1
        for j in prime:
            if i % j == 0:
                flag = 0
                break
        if flag == 1:
            prime.append(i)
    return prime

def cmb(n, r):
    if n - r < r: r = n - r
    if r == 0: return 1
    if r == 1: return n

    numerator = [n - r + k + 1 for k in range(r)]
    denominator = [k + 1 for k in range(r)]

    for p in range(2,r+1):
        pivot = denominator[p - 1]
        if pivot > 1:
            offset = (n - r) % p
            for k in range(p-1,r,p):
                numerator[k - offset] /= pivot
                denominator[k] /= pivot

    result = 1
    for k in range(r):
        if numerator[k] > 1:
            result *= int(numerator[k])

    return result
factor = factorization(M)[0]
ans = 1


for i in factor:
    ans *= cmb(N+i-1, i)
    ans %= 1000000007

print(ans)