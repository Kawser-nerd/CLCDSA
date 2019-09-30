import sys
import string
t = int(sys.stdin.readline())
for i in range(t):
	line = map(int, sys.stdin.readline().split())
	n = line[0]
	s = line[1:]
#	mn = min(s)
#	mnc = s.count(mn)
	x = sum(s)
	r = float(x) * 2 / n
	print  'Case #' + str(i+1) + ':',
	for j in range(n):
		for y in range(x + 1):
			sum1 = sum(map(lambda x: max(0, s[j] + y - x), s))
			if (sum1 >= x):
				nums = 1
				if ((sum1 > x) and y > 0):
					nums = len(filter(lambda x: (s[j] + y > x), s))
				print str(max(0, (float(y) - (float(sum1) - x)/nums) *100/x)),
				break
	print ''