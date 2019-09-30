import sys
sys.stdin = open('B-large.in', 'r')
sys.stdout = open('B-large.out', 'w')

for tc in range(int(input())):
	n1, n2 = map(int, input().split())

	s = []

	for i in range(n1+n2):
		a, b = map(int, input().split())
		s += [(a, b, 1 if i<n1 else 2)]

	s.sort(key = lambda x: x[0])

	aw, bw = 0, 0
	t = [[], [], []]

	# 0 = free 1 = a 2 = b

	for x in s:
		if x[2] == 1:
			aw += x[1] - x[0]
		else:
			bw += x[1] - x[0]

	first, last = s[0][2], s[-1][2]
	dur = 1440 - (s[-1][1] - s[0][0])

	if first==last:
		t[first].append(dur)
	else:
		t[0].append(dur)

	for i in range(len(s)-1):
		x, y = s[i][2], s[i+1][2]
		dur = s[i+1][0] - s[i][1]

		if x==y:
			t[x].append(dur)
		else:
			t[0].append(dur)

	t[1].sort(key = lambda x: -x)
	t[2].sort(key = lambda x: -x)

	r = len(t[0])

	aw += sum(t[1])
	bw += sum(t[2])

	i = 0
	while aw>720:
		aw -= t[1][i]
		i += 1
		r += 2

	i = 0
	while bw>720:
		bw -= t[2][i]
		i += 1
		r += 2

	print('Case #%d: %d' % (tc+1, r))