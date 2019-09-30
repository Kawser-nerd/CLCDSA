T = input()

vowels = 'aeiou'

def good(st, n):
	run = 0
	bestrun = 0
	for c in st:
		if c in vowels:
			bestrun = max(run, bestrun)
			run = 0 
		else:
			run += 1
	bestrun = max(run, bestrun)
	# print st, bestrun, n
	return (bestrun >= n)

def cnt(a, b):
	if b < a:
		return 0
	x = b - a + 1
	return (x * (x + 1)) / 2

for case in range(1, T+1):
	line = raw_input().strip().split()
	[s, n] = line
	n = int(n)

	ends = []
	ed = [False] * len(s)

	run = 0
	for i in range(len(s)):
		if s[i] in vowels:
			run = 0 
		else:
			run += 1
		if run >= n:
			ends.append(i)
			ed[i] = True

	B = 0
	le = None
	for i in range(len(s)):
		if ed[i]:
			le = i
		if le != None:
			B += le + 2 - n

	print "Case #%d: %d" % (case, B)