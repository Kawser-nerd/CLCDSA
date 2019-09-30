t = input()
N, J = map(int, raw_input().split())
s = pow(2,N/2-1)+1
print "Case #1:"
for i in xrange(J):
	t = "{0:b}".format(s)
	print t+t,
	for j in xrange(2,11):
		u = 0
		for k in t:
			u *= j
			u += ord(k)-ord('0')
		print u,
	print
	s += 2