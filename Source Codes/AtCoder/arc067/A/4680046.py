from collections import defaultdict as dd
primes = dd(int)
n = int(input())
for i in range(2,n+1):
  for j in range(2,int(i**.5)+2):
    while i%j == 0:
      i //= j
      primes[j] += 1
  if i > 1:
    primes[i] += 1
cnt = 1
mod = 10**9+7
for x in primes:
  cnt *= primes[x]+1
  cnt %= mod
print(cnt)