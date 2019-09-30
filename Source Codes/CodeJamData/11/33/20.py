import math
import itertools
import sys

# IS_PRIME = [False] * (10**4 + 1)
# PRIMES = []
# for i in xrange(2,10**4+1):
#   isPrime = True
#   for p in PRIMES:
#     if p > math.sqrt(i): break
#     if i % p == 0:
#       isPrime = False
#       break
#   if isPrime:
#     PRIMES.append(i)
#     IS_PRIME[i] = True
# 
# def find_prime_divisors(x):
#   global PRIMES
#   global IS_PRIME
# 
#   ret = {}
# 
#   for p in PRIMES:
#     if p > math.sqrt(x): break
#     if x % p == 0:
#       if p not in ret:
#         ret[p] = 0
#       ret[p] += 1
# 
#   return ret.items()

def product(seq):
  s = 1
  for x in seq:
    s *= x
  return s

def find_divisors(x, L, H):
  divisors = set()
  for i in xrange(1,int(math.sqrt(x))+1):
    if x % i == 0:
      if L <= i <= H: divisors.add(i)
      if L <= x / i <= H: divisors.add(x / i)
  return divisors

# This should also be ok
def find_multiples(x, L, H):
  multiples = set()
  l = L / x
  h = H / x
  for i in xrange(int(l), int(h)+1):
    if L <= x * i <= H: multiples.add(i*x)
  return multiples

# This part should be ok
T = int(sys.stdin.readline().strip())
for t in xrange(T):
  (N,L,H) = [int(a) for a in sys.stdin.readline().strip().split(' ')]
  ns = [int(a) for a in sys.stdin.readline().strip().split(' ')]

  ss = [None] * len(ns)
  for i in xrange(len(ns)):
    ss[i] = find_divisors(ns[i], L, H) | find_multiples(ns[i], L, H)
  ss.sort(key=len)

  s = ss[0]
  possible = True;
  for i in xrange(len(ss)):
    s = s & ss[i]
    if len(s) == 0:
      possible = False
      break
  if not possible:
    print "Case #" + str(t+1) + ": NO"
  else:
    print "Case #" + str(t+1) + ": " + str(min(s))
