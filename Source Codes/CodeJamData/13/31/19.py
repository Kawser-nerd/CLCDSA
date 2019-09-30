#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import math, os, sys, random

vowels = 'aeiou'
consonants = 'bcdfghjklmnpqrstvwxyz'
vowels_set = frozenset(vowels)
consonants_set = frozenset(consonants)


def single_test(IN, OUT):
  name, n = IN.readline().split()
  n = int(n)
  L = len(name)
  
  data = ''
  for l in name: data += 'v' if l in vowels_set else 'c'
  
  starts = []
  count = 0
  for i, l in enumerate(data):
    if l == 'v':
      count = 0
    else:
      count += 1
      if count >= n:
        starts.append(i + 1 - n)
  
  freespaces = []
  
  
  cs = 0
  for i in range(L):
    while cs != -1 and cs < len(starts) and i > starts[cs]:
      cs += 1
    if cs == len(starts):
      cs = -1
    
    if cs == -1:
      if i < L: freespaces.append((i, L - i))
    else:
      if starts[cs] + n - 1 > i: freespaces.append((i, starts[cs] + n - 1 - i))
  
  
  result = (L * (L + 1)) // 2
  
  for f in freespaces:
    result -= f[1]
  
  return result
  


def main(IN, OUT):
  T = int(IN.readline())
  for i in range(1, T+1):
    OUT.write('Case #%d: %d\n' % (i, single_test(IN, OUT)))


if __name__ == '__main__':
  assert len(sys.argv) == 2
  IN = open(sys.argv[1], 'rt')
  OUT = open('%s.out' % sys.argv[1][:-3], 'wt')
  main(IN, OUT)
  OUT.close()
  IN.close()

