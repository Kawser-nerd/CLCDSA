import sys

input = sys.stdin

T = int(input.readline())
for t in range(1, T + 1):
	print 'Case #{t}:'.format(t = t)
	D, N, A = [i for i in input.readline().split(' ')]
	D = float(D)
	N = int(N)
	A = int(A)
	Ss = []
	for i in range(N):
		Ss.append([float(i) for i in input.readline().split(' ')])
	As = [float(i) for i in input.readline().split(' ')]

	for i in range(A):
		a = As[i]
		ss = [0]
		for j in range(len(Ss)):
			s = Ss[j]
			if s[1] < D:
				ss.append(s[0] - (2 * s[1] / a) ** .5)
			elif j > 0 and Ss[j-1][1] < D:
				t0 = Ss[j-1][0]
				t1 = s[0]
				p0 = Ss[j-1][1]
				p1 = s[1]
				v = (p1 - p0) / (t1 - t0)
				tt = t0 + (D - p0) / v
				ss.append(tt - (2 * D / a) ** .5)
		t = max(ss) + (2 * D / a) ** .5
		print t
