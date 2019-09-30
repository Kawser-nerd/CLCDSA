def getnba(a, b, h):
	nb = 0
	na = (h+a-1) // a
	minna = nb
	minnb = na
	if b == 0:
		return minnb, minna
	while a <= h:
		nb += 1
		a += b
		na = (h + a - 1) // a
		if nb + na < minna + minnb:
			minnb = nb
			minna = na
	return minnb, minna

def getndc(neededTurn, d, H, A):
	if H <= A - d and neededTurn > 1:
		return -1, -1
	minnd = int(1e9)
	minnc = int(1e9)

	if d == 0:
		end = 0
	else:
		end = (A + d-1) // d

	for targetnd in range(end + 1):
		h = H
		a = A
		nd = 0
		nc = 0
		lastCure = False
		skip = False
		while nd < targetnd:
			nexta = max(0, a - d)
			if h - nexta <= 0:
				# Cure
				if lastCure:
					skip = True
					break
				lastCure = True
				nc += 1
				h = H
			else:
				# Debuff
				lastCure = False
				nd += 1
				a = nexta
			h -= a
			if h <= 0:
				return -1, -1

		if skip:
			continue


		remain = neededTurn
		lastCure = False
		skip = False
		while remain > 1:
			if h - a <= 0:
				if lastCure:
					skip = True
					break
				lastCure = True
				nc += 1
				h = H
			else:
				lastCure = False
				remain -= 1
			h -= a

		if skip:
			continue


		if nd + nc < minnd + minnc:
			minnd = nd
			minnc = nc

	if minnd >= int(1e9):
		return -1, -1

	return minnd, minnc


for x in range(1, int(input()) + 1):
	Hd, Ad, Hk, Ak, B, D = map(int, input().split())
	nB, nAd = getnba(Ad, B, Hk)
	neededTurn = nB + nAd
	nD, nC = getndc(neededTurn, D, Hd, Ak)
	if nD < 0:
		print('Case #%d: IMPOSSIBLE' % x)
	else:
		ans = neededTurn + nD + nC
		print('Case #%d: %d' % (x, ans))
