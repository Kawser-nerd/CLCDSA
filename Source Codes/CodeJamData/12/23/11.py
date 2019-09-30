import sys
import string
from itertools import *
t = int(sys.stdin.readline())
def powerset(iterable):
    s = list(iterable)
    return chain.from_iterable(combinations(s, r) for r in range(len(s)+1))
def printn(iterable):
	s = list(iterable)
	for i in s:
		print i,
	print ''
for i in range(t):
	line = map(int, sys.stdin.readline().split())
	n = line[0]
	s = line[1:]
	print  'Case #' + str(i+1) + ':'
	dic = {}
	found = 0
	for set1 in powerset(s):
		su = sum(set1)
		if (su in dic):
			printn(dic[su])
			printn(set1)
			found = 1
			break
		else:
			dic[su] = set1
	if (found < 1):
		print 'Impossible'
		
		