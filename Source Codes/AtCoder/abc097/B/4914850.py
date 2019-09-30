x = int(input())

def isPrime(n):
  if n%2 == 0 or n%3 == 0: return True
  if n<3: return False
  for i in range( 2, int(n**0.5) +1):
    if n%i == 0: return False
  return True

primes = [i for i in range(1, 32) if isPrime(i)]

def isExp(n):
  if n==1: return True
  for i in [p for p in primes if p<int(n**0.5)+1]:
    p = 0
    while i**p<=n:
      if i**p == n: return True
      p+=1
  return False

def solve():
  for i in range(x,0,-1):
    if isExp(i): return i

print(solve())