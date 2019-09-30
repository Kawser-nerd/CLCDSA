import sys
import math
import itertools

for testcase in xrange(1, int(sys.stdin.readline())+1):

  X, Y = [int(w) for w in sys.stdin.readline().split()]

  result = ''
  if X > 0:
  	for i in range(X):
  		result += 'WE'
  elif X < 0:
  	for i in range(int(math.fabs(X))):
  		result += 'EW'

  if Y > 0:
  	for i in range(Y):
  		result += 'SN'
  elif Y < 0:
  	for i in range(int(math.fabs(Y))):
  		result += 'NS'

  print 'Case #%d: ' % (testcase) + result