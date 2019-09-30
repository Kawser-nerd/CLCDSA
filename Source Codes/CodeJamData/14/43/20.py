#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @author: Danilo de Jesus da Silva Bellini
"""
C - Round 2
"""

import sys, os
from collections import deque

if sys.version_info.major == 2:
  range = xrange

def solve(width, height, blocks):
  m = [[False for x in range(width)] for y in range(height)]
  for x0, y0, x1, y1 in blocks:
    for x in range(x0, x1 + 1):
      for y in range(y0, y1 + 1):
        m[y][x] = True

  def is_unreach(x, y):
    return x < 0 or x >= width or y < 0 or y >= height or m[y][x]

  reached = 0
  while True:
    start = [(x, 0) for x in range(width) if not m[0][x]]
    finish = [(x, height-1) for x in range(width) if not m[height-1][x]]

    if not (start and finish):
      break

    path = [start[0]]
    directions = [0]

    while True:

      x, y = path[-1]
      if y == height - 1: # Found a path!
        reached += 1
        for p in path:
          x, y = p
          m[y][x] = True
        break

      neigh = deque([(x-1, y), (x, y+1), (x+1, y), (x, y-1)])
      neigh.rotate(directions[-1])
      neigh.pop() # Ignore backwards movement
      inv_neigh = (is_unreach(*n) or n in path for n in neigh)

      try:
        triples = zip(inv_neigh, [1, 0, 3], neigh)
        dir_change, new_pair = next((b, c) for a, b, c in triples if not a)
        path.append(new_pair)
        directions.append((directions[-1] + dir_change) % 4)
      except StopIteration:
        m[y][x] = True
        path.pop()
        directions.pop()
        if path:
          continue
        break

  return reached


# I/O processing
fname = sys.argv[1]
outfname = "output_" + os.path.splitext(os.path.split(fname)[1])[0] + ".txt"
with open(fname, "r") as fin:
  with open(outfname, "w") as fout:
    T = int(fin.readline())
    for case in range(1, T + 1):
      W, H, B = map(int, fin.readline().split())
      data = [list(map(int, fin.readline().split())) for unused in range(B)]
      result = solve(W, H, data)
      msg = "Case #{}: {} \n".format(case, result)
      fout.write(msg)
      print(msg)
