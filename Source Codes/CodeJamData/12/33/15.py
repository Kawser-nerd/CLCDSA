#!/usr/bin/env python
test = 'C-large'

input = open('%s.in'%test)
output = open('%s.out'%test, 'w')

# import sys
# output = sys.stdout

def solve(B, T, boxes, toys):
  cache = {}
  def head(N, skip, what):
    s = 0
    i = 0
    while s + what[i][0] <= skip:
      s += what[i][0]
      i += 1
      if i >= N:
        return (-1, 0)

    return (what[i][1], what[i][0] - (skip - s))

  def match(skip_b, skip_t):
    if cache.get((skip_b, skip_t)) is not None:
      return cache[(skip_b, skip_t)]
    box, box_count = head(B, skip_b, boxes)
    toy, toy_count = head(T, skip_t, toys)
    res = None
    if box == -1 or toy == -1:
      res = 0
    else:
      if box == toy:
        m = min(box_count, toy_count)
        res = match(skip_b+m, skip_t+m) + m
      else:
        res = max(match(skip_b, skip_t+toy_count), match(skip_b+box_count, skip_t))
    cache[(skip_b, skip_t)] = res
    return res
  res = match(0, 0)
  return res


T = int(input.readline())
for t in xrange(T):
  B, T = map(int, input.readline().split())
  _boxes = map(int, input.readline().split())
  _toys  = map(int, input.readline().split())
  boxes = []
  for i in xrange(B):
    boxes.append((_boxes[2*i], _boxes[2*i+1]))
  toys = []
  for i in xrange(T):
    toys.append((_toys[2*i], _toys[2*i+1]))
  print >>output, "Case #%s:"%(t+1), solve(B, T, boxes, toys)
