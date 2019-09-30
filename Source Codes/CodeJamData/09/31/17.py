import sys

def solve(case, input):
	countmap = {}
	for c in list(input):
		if not c in countmap:
			countmap[c] = 1
		else:
			countmap[c] += 1
	base = len(countmap)
	if base<2:
		base = 2
	values = {}
	value = 0
	mult = base**(len(input)-1)
	result = 0
	values[input[0]] = 1
	for i in range(len(input)):
		c = input[i]
		if c not in values:
			values[c] = value
			value += 1
			if value==1:
				value=2
		result += mult*values[c]
		mult/=base
	print "Case #%d: %d" % (case, result)

if __name__=='__main__':
	N = int(sys.stdin.readline().strip())
	for n in xrange(N):
		solve(n+1, sys.stdin.readline().strip())
