#!/bin/env python
import math

cases = int(raw_input())

for c in xrange(cases):
  tree_count = int(raw_input())
  dims = []
  for t in xrange(tree_count):
  	dims.append(map(int, raw_input().split()))

  print "Case #{}:".format(c+1)
  for i, p in enumerate(dims):
  	rest = [d for d in dims if d[0] != p[0] or d[1] != p[1]]
  	angles = [math.atan2(r[1]-p[1], r[0]-p[0]) for r in rest]
  	#print angles
  	angles = angles + [a + 2*math.pi for a in angles] + [a + 4*math.pi for a in angles]
  	angles.sort()
  	#print angles
  	end = 0

  	min_remove = 999999999
  	for start in xrange(len(angles) / 2):
  		while angles[end] < (angles[start] + math.pi - 1e-12):
  			end += 1
  		min_remove = min(min_remove, end - start - 1)
  	if min_remove == 999999999:
  		min_remove = 0
  	print min_remove