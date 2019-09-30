#!/usr/bin/env python3

from sys import stdin, stdout, stderr

import heapq

def solve(N, hikers):
  N = len(hikers)
  # hikers[i] = (D[i], M[i])
  D = [h[0] for h in hikers]
  M = [h[1] for h in hikers]
  # Among equal positions, put faster hikers first because we might have already seen them
  intersects = [((360 - D[i]) * M[i], M[i], i) for i in range(N)]
  heapq.heapify(intersects)
  best = N
  current = best
  seen = set()
  while current <= 2 * N:
    (m, M, i) = heapq.heappop(intersects)
    if i not in seen:
      current -= 1
      best = min(best, current)
      seen.add(i)
    else:
      current += 1
    heapq.heappush(intersects, (m + M * 360, M, i))
  return best

def main():
  T = int(input())
  for case in range(1, T + 1):
    N = int(input())
    hikers = []
    for i in range(N):
      D, H, M = map(int, input().split())
      for j in range(H):
        hikers.append((D, M + j))
    answer = solve(N, hikers)
    print("Case #%d: %s" % (case, answer))

main()

