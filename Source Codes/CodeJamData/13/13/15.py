#!/usr/bin/python2
#-*- coding: utf-8 -*-

import random

def readint(): return int(raw_input())
def readarray(f): return map(f, raw_input().split())

readint()
print 'Case #1:'

R, N, M, K = readarray(int)

primes = [2, 3, 5]

def decompose(n):
  l = []
  p = primes[:]
  while n > 1:
    if n % p[0] == 0:
      l.append(p[0])
      n /= p[0]
    else:
      p = p[1:]
  return l

def merge(p, q):
  l = []
  while len(p) > 0 or len(q) > 0:
    if len(p) == 0:
      l.extend(q)
      break
    elif len(q) == 0:
      l.extend(p)
      break
    else:
      if p[0] == q[0]:
        l.append(p[0])
        p = p[1:]
        q = q[1:]
      elif p[0] < q[0]:
        l.append(p[0])
        p = p[1:]
      else:
        l.append(q[0])
        q = q[1:]
  return l

random.seed()

for r in range(R):
  P = readarray(int)
  digits = []
  for p in P:
    digits = merge(digits, decompose(p))
  
  low_digits = filter(lambda x: x <= M/2, digits)
  
  while len(digits) > N:
    if len(low_digits) < 2:
      break
    p = random.choice(low_digits)
    low_digits.remove(p)
    digits.remove(p)
    really_low = filter(lambda x: x <= M/p, low_digits)
    if len(really_low) == 0:
      break
    q = random.choice(really_low)
    low_digits.remove(q)
    digits.remove(q)
    p = p*q
    if p <= M/2:
      low_digits.append(p)
    digits.append(p)

  if len(digits) > N:
    digits = digits[:N]

  while len(digits) < N:
    digits.append(random.randint(2, M))

  print ''.join(map(str, digits))
