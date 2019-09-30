inpl = lambda: list(map(int,input().split()))
MOD = 10**9 + 7
N, M = inpl()
 
def factorize(n):
  prime_list = []
  factorize_list = []
  i = 2
  while i*i <= n:
    for p in prime_list:
      if i % p == 0:
        break
    else:
      prime_list.append(i)
      k = 0
      while n % i == 0:
        n //= i
        k += 1
      factorize_list.append(k)
    i += 1
  if n > 1:
    factorize_list.append(1)
  return(factorize_list)

def H(n,k):
  h = 1
  L = n + k - 1
  k = min(n-1,k)
  for j in range(k):
    h *= L-j
  for j in range(k):
    h //= j+1
  return h

ans = 1
for k in factorize(M):
  ans *= H(N,k) % MOD
  ans %= MOD

print(ans)