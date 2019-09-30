#!/usr/bin/env python3

from sys import stdin, stdout, stderr

import itertools

def solve(R, C, N):
  best = float('+inf')
  positions = {(i, j) for j in range(C) for i in range(R)}
  for combination in itertools.combinations(positions, N):
    penalty = 0
    for i in range(R):
      for j in range(C):
        if (i, j) in combination and (i + 1, j) in combination:
          penalty += 1
        if (i, j) in combination and (i, j + 1) in combination:
          penalty += 1
    best = min(best, penalty)
  return best

def main():
  T = int(input())
  for case in range(1, T + 1):
    R, C, N = map(int, input().split())
    answer = solve(R, C, N)
    print("Case #%d: %s" % (case, answer))

main()

