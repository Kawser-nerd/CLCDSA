import sys
sys.setrecursionlimit(10**7)
INF = 10 ** 18
MOD = 10 ** 9 + 7
from functools import partial, reduce
from operator import mul
prod = partial(reduce, mul)
def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x) - 1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def II(): return int(sys.stdin.readline())
def SI(): return input()

from collections import Counter
primes = list(range(1001))
primes[1] = 0
for i in range(2, int(1000 ** 0.5) + 1):
    if primes[i]:
        for j in range(2 * i, 1001, i):
            primes[j] = 0
primes = [p for p in primes if p != 0]

def main():
    N = II()
    primefactors = Counter()
    for n in range(1, N+1):
        for p in primes:
            if n == 1:
                break
            while n % p == 0:
                primefactors[p] += 1
                n //= p
    ans = reduce(lambda x, y: x * (y+1), primefactors.values(), 1) % MOD
    return ans

print(main())