import math
T = int(raw_input())

for t in range(T):
	line = [i.strip() for i in raw_input().split()]
	x = int(line[0])
	y = int(line[1])

	path = [' ' for i in range((abs(x)+abs(y))*2)]

	for i in range(abs(x)):
		if x > 0:
			path[2*i] = 'W'
			path[2*i+1] = 'E'
		else:
			path[2*i] = 'E'
			path[2*i+1] = 'W'

	m = 2*abs(x)
	for i in range(abs(y)):
		if y > 0:
			path[m + 2*i] = 'S'
			path[m + 2*i + 1] = 'N'
		else:
			path[m + 2*i] = 'N'
			path[m + 2*i + 1] = 'S'

	print 'Case #%s: %s' % (t+1, "".join(path))
