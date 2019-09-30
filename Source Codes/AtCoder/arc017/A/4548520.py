n = int(input())
def sieve(x):
    if x < 2: return []
    primes = [i for i in range(x)]
    primes[1] = 0
    for p in primes:
        if p > x ** (1/2): break
        if p == 0: continue
        for np in range(2 * p, x, p): primes[np] = 0
    return [p for p in primes if p != 0]

PS = sieve(10**6)
if n in PS:
  print("YES")
else:
  print("NO")