#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import math, os, sys, random


def single_test(IN, OUT):
  X, Y = map(int, IN.readline().split())
  
  x, y = 0, 0
  result = ''
  step = 1
  
  while True:
    E = X - x + random.random()
    N = Y - y + random.random()
    W = -E + random.random()
    S = -N + random.random()
    d = max(E, N, W , S)
    nx, ny = x, y
    r = 'O'
    if E == d:
      nx += step
      r = 'E'
    elif N == d:
      ny += step
      r = 'N'
    elif W == d:
      nx -= step
      r = 'W'
    elif S == d: 
      ny -= step
      r = 'S'
    if abs(X - nx) + abs(Y - ny) < abs(X - x) + abs(Y - y):
      step += 1
      result += r
      x, y = nx, ny
    else:
      break
  
  while (x, y) != (X, Y):
    if Y > y:
      result += 'SN'
      y += 1
    elif Y < y:
      result += 'NS'
      y -= 1
    elif X > x:
      result += 'WE'
      x += 1
    elif X < x:
      result += 'EW'
      x -= 1
  
  return result
  


def main(IN, OUT):
  T = int(IN.readline())
  for i in range(1, T+1):
    OUT.write('Case #%d: %s\n' % (i, single_test(IN, OUT)))


if __name__ == '__main__':
  assert len(sys.argv) == 2
  IN = open(sys.argv[1], 'rt')
  OUT = open('%s.out' % sys.argv[1][:-3], 'wt')
  main(IN, OUT)
  OUT.close()
  IN.close()

