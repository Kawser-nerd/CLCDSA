from collections import defaultdict

primes = defaultdict(int)

N = int(input())

import itertools
def prime_factors(n):
    for i in itertools.chain([2], itertools.count(3, 2)):
        if n <= 1:
            break
        while n % i == 0:
            n //= i
            yield i

for i in range(1, N+1):
    for p in prime_factors(i):
        primes[p] += 1

total = 1
for c in primes.values():
    total *= c + 1
print(total % (10**9 + 7))