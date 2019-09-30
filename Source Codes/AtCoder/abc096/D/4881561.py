import math

N = int(input())

def isPrime(n):
  if n==2 or n==3: return True
  for i in range(2, int(n**0.5)+1):
    if n%i == 0:
      return False
  return True

primes = [str(i) for i in range(2, 55555+1) if i%5==1 and isPrime(i)]
print(' '.join(primes[0:N]))