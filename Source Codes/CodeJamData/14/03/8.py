T = int(raw_input())

for t in xrange(T):
	print "Case #%d:" % (t+1)

	R,C,M = map(int, raw_input().split())
	if C == 1:
		ans = M*'*' + (R-M-1)*'.' + 'c'
		print '\n'.join(list(ans))
		continue

	if R == 1:
		print M*'*' + (C-M-1)*'.' + 'c'
		continue

	clean = R*C-M
	if clean == 1:
		print '\n'.join(['c'+'*'*(C-1)] + ['*'*C]*(R-1))
		continue

	if clean in [2, 3, 5, 7] or ( (R == 2 or C == 2) and clean%2 != 0):
		print "Impossible"
		continue

	bd = [2, 2] + [0 for x in xrange(R-2)]
	crea = 2
	clean -= 4

	while clean:
		done = False
		if clean >= 2:
			if bd[0] == 2 and C != 2:
				bd[0] = bd[1] = 3
				clean -= 2
				done = True
			else:
				if crea < R:
					bd[crea] = 2
					crea += 1
					clean -= 2
					done = True

				if not done and bd[0] != C:
					bd[0] += 1
					bd[1] += 1
					clean -= 2
					done = True

		if not done:
			idx = [bd[x] == C for x in xrange(2, R)].index(False) + 2
			bd[idx] += 1
			clean -= 1

	for index, x in enumerate(bd):
		if index == 0:
			print 'c' + '.'*(x-1) + '*'*(C-x)
		else:
			print '.'*x + '*'*(C-x)


