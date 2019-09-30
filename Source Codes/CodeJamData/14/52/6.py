cases = int(raw_input())

for case in range(1, cases + 1):
	P, Q, n = tuple([int(i) for i in raw_input().split()])
	H = [0] * n
	G = [0] * n
	T = [0] * n
	R = [0] * n
	for i in range(n):
		h, g = tuple([int(j) for j in raw_input().split()])
		H[i] = h
		G[i] = g
		t = 0
		while h > 0:
			if h - Q * (((h + Q - 1) / Q) - 1) <= P:
				break
			h -= P
			t += 1
		if h > 0:
			R[i] = ((h + Q - 1) / Q) - 1
			T[i] = t + 1
		else:
			T[i] = -1
	'''
	res = 0
	for i in range(1 << n):
		t = 1
		tmp = 0
#		print i
		for j in range(n):
			if i & (1 << j):
				if T[j] == -1:
					break
				p = T[j]
				q = R[j]
				if p > q + t:
					break
				tmp += G[j]
				t = q + t - p
			else:
				q = (H[j] + Q - 1) / Q
				t += q
#			print ' ', t, tmp
		if res < tmp:
			res = tmp
	res2 = res
	'''
	D = {1: 0}
	N = {}
	for i in range(n):
		for j in D:
			q = (H[i] + Q - 1) / Q
			if (q + j) in N:
				N[q + j] = max(N[q + j], D[j])
			else:
				N[q + j] = D[j]

			if T[i] != -1:
				p = T[i]
				q = R[i]
#				print p, q, j, q + j - p
				if p <= q + j:
					if (q + j - p) in N:
						N[q + j - p] = max(N[q + j - p], D[j] + G[i])
					else:
						N[q + j - p] = D[j] + G[i]
		D, N = N, {}
#		print D

	res = 0
	for i in D:
		if res < D[i]:
			res = D[i]
	'''
	if res != res2:
		print case, n, P, Q, res, res2
	'''

	print "Case #%d: %d" % (case, res)
