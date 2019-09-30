
filename = "C-small.in"

ll = -1
for line in open(filename, "r"):
	ll += 1
	if ll == 0: continue

	data = map(lambda x: long(x), line.rstrip().split())

	ret = 0
	for a in range(data[0], data[1] + 1):
		b_min = max((a + 1) / 2, data[2])
		b_max = min(a * 2, data[3])
		if b_min > b_max:
			ret += data[3] - data[2] + 1
			continue
		ret += b_min - data[2] + data[3] - b_max
		bs = range(b_min, b_max + 1)
		for b in bs:
			atmp = a
			turn = 1
			while True:
				if atmp > b:
					if (atmp - 1) / b >= 2:
						break
					else:
						atmp -= b
				elif atmp == b:
					turn += 1
					break
				else:
					if (b - 1) / atmp >= 2:
						break
					else:
						b -= atmp
				turn += 1
			if turn % 2 == 1:
				ret += 1
	
	print "Case #%d: %d" % (ll, ret)
