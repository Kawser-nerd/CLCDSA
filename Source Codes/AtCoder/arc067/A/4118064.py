from functools import reduce


def primes_list(N):
    l = [v for v in range(2, N+1)]
    ret = []
    while l:
        cur = l.pop(0)
        l = list(filter(lambda x: x % cur != 0, l))
        ret.append(cur)
    return ret


mod = 10**9+7
N = int(input())

l = [0]*(N+1)
primes = primes_list(N)

for i in range(2, N+1):
    for p in primes:
        if p > i:
            break
        tmp = 0
        while i % p == 0:
            i //= p
            tmp += 1
        l[p] += tmp

ans = 1
for i in l:
    if i == 0:
        continue
    else:
        ans = ans*(i+1) % mod
print(ans)