t = int(raw_input())

def vowel(c):
	return c in 'aeiou'

for kei in xrange(t):
	name, n = raw_input().split()
	n = int(n)
	i = 0
	j = 0
	ctr = 0
	cons = 0
	start = []
	m = -1
	while i < len(name):
		if not vowel(name[i]):
			while j < len(name) and not vowel(name[j]):
				j += 1
			while j-i >= n:
				start.append(i)
				m = max(m,i)
				i += 1
			i = j
		else:
			i += 1
			j = i
	ctr = 0
	j = 0
	for i in xrange(len(name)):
		while j < len(start) and start[j] < i:
			j += 1
		if j >= len(start):
			break
		#print((i,start[j]+n-1))
		ctr += len(name)-(start[j]+n-1)
	print('Case #%d: %d' % (kei+1, ctr))
