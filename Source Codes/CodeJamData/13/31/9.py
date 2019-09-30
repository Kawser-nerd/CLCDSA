import sys
import math
import itertools

for testcase in xrange(1, int(sys.stdin.readline())+1):

  name, n = [str(w) for w in sys.stdin.readline().split()]
  n = int(n)

  starting_points = {}

  enough_consants = False
  num_consecutive = 0
  for index in xrange(len(name)-1,-1, -1):
  	if name[index] in 'aeiou':
  		num_consecutive = 0
  	else:
  		num_consecutive += 1
  	if num_consecutive >= n:
  		starting_points[index] = 1

  if 0 in starting_points:
  	count = 1
  	last_used = 1
  else:
  	count = 0
  	last_used = 0

  for index in xrange(n, len(name)):
  	index_minus = index - n + 1
  	if index_minus in starting_points:
  		count = count + index_minus + 1
  		last_used = index_minus + 1
  	else:
  		count = count + last_used

  print 'Case #%d: %d' % (testcase, count)


  # for i in xrange(A):
  #   x *= p[i]
  #   best = min(best, (B - i) + (A - i - 1) + (B + 1) * (1 - x))

  # 