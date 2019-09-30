import sys

threshold = 400

f = open(sys.argv[1])
for t in range(1, int(f.readline())+1):
	N = int(f.readline())
	s = map(int, f.readline().split())
	
	too_close = 0
	for index, i in enumerate(s):
		diff = i - index
		if diff <= 200 and diff >= 0:
			too_close += 1

	if too_close >= 200:
		print 'Case #%d: BAD' % (t)
	else:
		print 'Case #%d: GOOD' % (t)
