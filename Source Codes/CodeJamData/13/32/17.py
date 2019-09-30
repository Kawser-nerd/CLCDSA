t = int(raw_input())

for kei in xrange(t):
	x,y = (int(j) for j in raw_input().split())
	ans = []
	while x > 0:
		ans.append('WE')
		x -= 1
	while x < 0:
		ans.append('EW')
		x += 1
	while y > 0:
		ans.append('SN')
		y -= 1
	while y < 0:
		ans.append('NS')
		y += 1
	print('Case #%d: %s' % (kei+1, ''.join(ans)))