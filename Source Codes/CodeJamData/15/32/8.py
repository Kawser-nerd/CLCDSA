
import sys
import math
from collections import defaultdict

f = open('B-large.in')
#f = open('test')
tests = int(f.readline())

def getOffset(keys, target):
	s = set(list(keys))
	for c in target:
		if c not in s:
			return 0
	offset = 1
	while offset < len(target):
		if target[:len(target) - offset] == target[offset:]:
			break
		offset += 1
	return offset
	#return (s - len(target))//offset



def getExp(keys, target, s):
	d = defaultdict(lambda: 0.0)
	for c in keys:
		d[c] += 1.0/len(keys)
	tot = 1.0
	for c in target:
		tot *= d[c]
	return tot * (s - len(target) + 1)
	'''
	offset = 0
	while offset < len(target):
		if all(target[:len(target) - offset] == target[offset:]):
			
		offset += 1
	'''
	


for t in xrange(tests):
	k,l,s = map(int, f.readline().rstrip().split())
	keys = f.readline().rstrip()
	target = f.readline().rstrip()
	offset = getOffset(keys, target)
	if offset == 0:
		print "Case #" + str(t + 1) + ": 0.0"
		continue
	needed = 1 + (s - len(target))//offset
	ans = max(0.0, needed - getExp(keys, target, s))
	if ans < 0.000000001:
		ans = 0.0
	print "Case #" + str(t + 1) + ": " + str(ans)
	



#
#sys.stdin.readline().rstrip()

