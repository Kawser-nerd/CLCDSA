#!/usr/bin/python

import os
import sys
import bisect

primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, \
67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, \
139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, \
223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, \
293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, \
383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, \
463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, \
569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, \
647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, \
743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, \
839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, \
941, 947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013, 1019, 1021, \
1031, 1033, 1039]

def first_prime(P):
  idx = bisect.bisect_left(primes, P)
  n = len(primes)
  if idx < n - 1 and primes[idx + 1] == P:
    return idx + 1
  else:
    return idx


def group_sets(A, B, P):
  sets = range(A, B + 1)
  nn = len(sets)
  change = True
  idx0 = first_prime(P)
  for i in xrange(A, B + 1):
    for j in xrange(i + 1, B + 1):
      idx = idx0
      p = primes[idx]
      while p <= i:
        if i%p == 0 and j%p == 0:
          to_set = sets[i - A]
          from_set = sets[j - A]
          if to_set != from_set:
            for k in xrange(nn):
              if sets[k] == from_set:
                sets[k] = to_set
        idx += 1
        p = primes[idx]
  dist_sets = set()
  for k in xrange(nn):
    dist_sets.add(sets[k])
  return len(dist_sets)


def run(inf):
  C = int(inf.readline().strip())
  for nc in xrange(1, C + 1):
    (A, B, P) = [int(x) for x in inf.readline().strip().split()]
    print "Case #%d: %d" % (nc, group_sets(A, B, P))


run(sys.stdin)
