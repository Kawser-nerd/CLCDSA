import sys
import math
from fractions import Fraction

si = sys.stdin
so = sys.stdout
se = sys.stderr

readLine = raw_input
readArgs = lambda : readLine().split()
readInts = lambda : map(int, readArgs())
readInt = lambda : readInts()[0]

def process(x):
	if not x:
		return ''
	ret = x[0]
	for i in range(1, len(x)):
		if x[i - 1] != x[i]:
			ret += x[i]
	return ret

def analyze(x):
	if not x:
		return []
	cur = x[0]
	cnt = 1
	ret = []
	for i in range(1, len(x)):
		if x[i - 1] == x[i]:
			cnt += 1
		else:
			ret.append(cnt)
			cnt = 1
			cur = x[i]
	ret.append(cnt)
	return ret

T = readInt()
for t in range(1, T + 1):
	N = readInt()
	tokens = [readLine() for i in range(N)]
	print 'Case #%d:' % t,
	# Compress first
	ntokens = set(map(process, tokens))
	if len(ntokens) > 1:
		print 'Fegla Won'
		continue
	ndata = map(analyze, tokens)
	lim = len(ndata[0])
	Ans = 0
	ans = 0
	for i in range(lim):
		ans = 0xFFFFFFFF
		for cost in range(1, 120):
			S = 0
			for j in ndata:
				S += abs(j[i] - cost)
			ans = min(ans, S)
		Ans += ans
	print Ans
