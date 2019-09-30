#!/usr/bin/python


def xor(a, b):
	c = ""
	for i in xrange(len(a)):
		c += "01"[int(a[i]) ^ int(b[i])]
	return c

T = int(raw_input().strip())

for tc in xrange(1, T + 1):
	print "Case #%d:" % tc,
	n, l = map(int, raw_input().strip().split())
	flow = raw_input().strip().split()
	devices = raw_input().strip().split()
	#
	minAnswer = 9999
	for socket in xrange(n):
		flips = xor(flow[socket], devices[0])
		modflows = [xor(flow[i], flips) for i in xrange(n) if i != socket]
		good = True
		for i in xrange(1, n):
			if devices[i] not in modflows:
				good = False
				break
		if good:
			minAnswer = min(minAnswer, len(filter(lambda c: c == '1', list(flips))))
	answer = minAnswer >= 9999 and "NOT POSSIBLE" or str(minAnswer)
	print answer
	