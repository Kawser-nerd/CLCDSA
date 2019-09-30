from __future__ import division
import sys

def do_case(l, h, ns):
	for mine in xrange(l, h+1):
		good = True
		for his in ns:
			if mine % his != 0 and his % mine != 0:
				good = False
				break
		if good:
			return mine
	return "NO"



in_, out_f= sys.argv[1], sys.argv[1]+".out"
out = open(out_f, 'w')
with open(in_, 'r') as file:
	num = 1
	num_cases = int(file.next().rstrip())
	for num in range(1, num_cases+1):
		n, l, h = map(int, file.next().rstrip().split(' '))
		ns = map(int, file.next().rstrip().split(' '))

		ret = do_case(l, h, ns)

		out.write("Case #%d: %s\n" % (num, ret))
		print "Case #%d: %s" % (num, ret)

