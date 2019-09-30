#!/bin/env python

cases = int(raw_input())

for i in xrange(cases):
  sample_count = int(raw_input())
  samples = map(int, raw_input().split())
  max_dec = 0
  prev = 0
  eaten1 = 0
  for x in samples:
  	eaten1 += max(0, prev - x)
  	max_dec = max(max_dec, prev - x)
  	prev = x
  prev = 0
  eaten2 = 0
  for x in samples:
  	eaten2 += min(prev, max_dec)
  	prev = x
  print "Case #{}: {} {}".format(i+1, eaten1, eaten2)