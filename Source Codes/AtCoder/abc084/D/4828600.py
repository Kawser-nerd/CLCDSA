import bisect
from numpy import cumsum
order = 5
q = int(input())
lr = [[int(item) for item in input().split()] for _ in range(q)]

def sieve(n):
    is_prime = [True for _ in range(n+1)]
    is_prime[0] = False
    is_prime[1] = False
    for i in range(2, int(n**0.5) + 1):
        if not is_prime[i]:
            continue
        for j in range(i * 2, n+1, i):
            is_prime[j] = False
    return [i for i in range(n+1) if is_prime[i]]

sosu = sieve(10**order)
like2017 = [0] * (10**order+1)
for s in sosu:
    if s % 4 == 1 or s==3:
        index = bisect.bisect_left(sosu, (s + 1) // 2)
        if sosu[index] == (s + 1) // 2:
            like2017[s] = 1
cs = cumsum(like2017)

for l, r in lr:
    print(cs[r] - cs[l-1])