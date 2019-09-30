#!/usr/bin/env python3

from sys import stdin, stdout, stderr

import collections

best = {}

def precompute():
  best[1] = 1
  queue = collections.deque([1])
  limit = 1000000
  while queue:
    i = queue.popleft()
    d = best[i]
    if d > limit:
      break
    if i + 1 not in best and i + 1 <= limit * 10:
      best[i + 1] = d + 1
      queue.append(i + 1)
    rev = int("".join(reversed(str(i))))
    if rev not in best and rev <= limit * 10:
      best[rev] = d + 1
      queue.append(rev)

def solve(N):
  return best[N]

def main():
  T = int(input())
  for case in range(1, T + 1):
    N = int(input())
    answer = solve(N)
    print("Case #%d: %s" % (case, answer))

precompute()
main()

