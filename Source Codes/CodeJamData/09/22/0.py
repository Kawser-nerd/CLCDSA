def next_permutation(s):
	for i in xrange(len(s)-1, 0, -1):
		if s[i] > s[i-1]:
			break
	else:
		return []
	k = i
	for j in xrange(i, len(s)):
		if s[k] >= s[j] and s[j] > s[i-1]:
			k = j
	t = s[i-1]
	s[i-1] = s[k]
	s[k] = t
	s[i:] = s[len(s)-1:i-1:-1]
	return s
	
	

if __name__ == '__main__':
	N = int(raw_input())
	for i in xrange(N):
		v = raw_input()
		s = [x for x in v if x != '0']
		s.sort()
		while len(s) <= len(v):
			s[1:1] = '0'
		s = (''.join(s))
		q = next_permutation(list(v))
		if q:
			s = ''.join(q)
		print 'Case #%d:' % (i+1), s

