from __future__ import division
import sys
from itertools import cycle, islice

def do_case(l, t, n, c, _as):
	distances = list(islice(cycle(_as), n))
	total = sum(distances)

#	print l, t, n, c, total, distances, '::', _as
	if total*2 <= t or l == 0:
		return total*2

	traveled = t * .5
	left = 0
	index = 0
	for i,dist in enumerate(distances):
		if traveled >= dist:
			traveled -= dist
		else:
			index = i+1
			left = dist - traveled
			break
#	print left, index
	remaining = distances[index:] + [left]
#	print t, remaining
#	print sum(remaining) * 2
#	print list(islice(sorted(remaining, reverse=True),l)), sum(islice(sorted(remaining, reverse=True),l))
	return t + sum(remaining) * 2 - sum(islice(sorted(remaining, reverse=True),l))


in_, out_f= sys.argv[1], sys.argv[1]+".out"
out = open(out_f, 'w')
with open(in_, 'r') as file:
	num = 1
	num_cases = int(file.next().rstrip())
	for num in range(1, num_cases+1):
		s = map(int, file.next().rstrip().split(' '))
		l, t, n, c = s[0:4]
		_as = s[4:]

		ret = do_case(l, t, n, c, _as)

		out.write("Case #%d: %d\n" % (num, ret))
		print "Case #%d: %d" % (num, ret)
