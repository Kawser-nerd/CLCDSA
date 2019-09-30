def solve(a):
	b = int(a.split(" ")[0])
	m = int(a.split(" ")[1])
	if m > 2**(b-2):
		print "IMPOSSIBLE"
		return

	a = [[0 for i in xrange(b)] for j in xrange(b)]
	for i in xrange(b):
		for j in xrange(i+1, b):
			a[i][j] = 1
	current = 2**(b-2)
	bias = b-3
	# print current, m, bias
	while (current > m and bias >= 0):
		if (current - 2**bias >= m):
			a[bias + 1][b-1] = 0
			# print bias + 2, b - 1
			current -= 2**bias
		bias -= 1

	if (current != m):
		print "IMPOSSIBLE"
	else:
		print "POSSIBLE"
		for i in xrange(b):
			print "".join([str(w) for w in a[i]])

file = open("B-large.in", "r")
a = file.readlines()
T = int(a[0])
for i in xrange(T):
	print "Case #%d:" % (i+1),
	solve(a[i+1])
