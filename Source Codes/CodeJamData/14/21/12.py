#!/usr/bin/python

def conv(s):
	ans = []
	for i in xrange(len(s)):
		if i != 0 and s[i] == s[i-1]:
			ans[-1] = (ans[-1][0], ans[-1][1]+1)
		else:
			ans.append((s[i], 1))
	return ans

def do():
	n = input()
	strs = [conv(raw_input()) for i in xrange(n)]
	flat = set([''.join(s[0] for s in st) for st in strs])
	if len(flat) != 1:
		return "Fegla Won"
	ans = 0
	#print zip(*strs)
	for i in zip(*strs):
		best = 10000000000
		for attempt in xrange(1, 101):
			res = 0
			for j in i:
				res += abs(j[1] - attempt)
			if res < best:
				best = res
		ans += best
	return str(ans)

T = input()
for i in xrange(1, T+1):
	print "Case #%s: %s" % (i, do())



	
