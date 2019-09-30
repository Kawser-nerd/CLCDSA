

def gcd(a,b):
	while True:
		if b>a:
			a,b = b,a
		if b==0:
			return a
		a %= b

T = int(raw_input())

for t in xrange(1, T+1):
	H, W, D = map(int, raw_input().split())
	ms = set()
	orig = None
	for r in xrange(H):
		line = raw_input()
		for c in xrange(W):
			if line[c]=='#':
				ms.add((c,r))
			elif line[c]=='X':
				orig = (c,r)
	
	count = 0
	for c in xrange(-D, D+1):
		for r in xrange(-D, D+1):
			#print '###',c,r
			ac = abs(c)
			ar = abs(r)
			dc = c/max(ac,1)
			dr = r/max(ar,1)
			#if dr<0 or dc<0:continue
			#if ac>ar: continue
			
			if gcd(ac, ar) != 1:
				continue
			
			pairs = []
			for cc in range(ac):
				pairs.append((2*ar*(2*cc+1),(+1,0)))
			for rr in range(ar):
				pairs.append((2*ac*(2*rr+1),(0,+1)))
			pairs.sort()
			steps = []
			while pairs:
				if len(pairs)>1 and pairs[0][0]==pairs[1][0]:
					steps.append((1,1))
					del pairs[:2]
				else:
					steps.append(pairs[0][1])
					del pairs[0]
			
			reps = 0
			fc,fr = ac,ar
			while fc*fc + fr*fr <= D*D:
				reps += 1
				fc += ac
				fr += ar
			ec,er = orig
			#print
			#print
			#print '#####',dc*ac,dr*ar,':',
			for _ in range(reps):
				stopped = False
				for step in steps:
					#print
					#print (step[0]*dc,step[1]*dr),':',(ec,er),'>',
					if step==(1,1):
						if (ec+dc, er+dr) in ms:
							hor = (ec+dc, er)
							ver = (ec, er+dr)
							if hor not in ms and ver not in ms:
								stopped = True
								break
							elif hor in ms and ver in ms:
								dc = -dc
								dr = -dr
							elif hor in ms:
								dc = -dc
								er += dr
							elif ver in ms:
								dr = -dr
								ec += dc
						else:
							ec += dc
							er += dr
					elif step==(1,0):
						if (ec+dc, er) in ms:
							dc = -dc
						else:
							ec += dc
					elif step==(0,1):
						if (ec, er+dr) in ms:
							dr = -dr
						else:
							er += dr
					#print (ec,er),
				if stopped:
					break
				if (ec,er) == orig:
					count += 1
					break
	
	print 'Case #%s: %s'%(t, count)





