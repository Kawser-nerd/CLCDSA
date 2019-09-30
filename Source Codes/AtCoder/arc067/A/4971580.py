import math
N = int(input())
ans = 0
s = 0
primes = [2]
i = 3
while i <= N:
    all(i % p != 0 for p in primes) and primes.append(i)
    i += 2
l = [0] * len(primes)
for i, p in enumerate(primes):
    j = 1
    while p ** j <= N:
        l[i] += (N // (p ** j))
        j += 1
ans = 1
for n in l:
    ans *= (n + 1)
print(ans % (10 ** 9 + 7))