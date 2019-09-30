import math

for L in range(int(input())):
	nAc,nAj = [t(s) for t,s in zip((int,int),input().split())]
	
	Ac = []
	Aj = []
	
	for _ in range(nAc):
		Ac.append([t(s) for t,s in zip((int,int),input().split())])
	for _ in range(nAj):
		Aj.append([t(s) for t,s in zip((int,int),input().split())])
	
	#0 = any, 1 = cameron busy, 2 = james busy
	con = [0]*1440 # constraints
	for C,D in Ac:
		for i in range(C,D):
			con[i] = 1
	for C,D in Aj:
		for i in range(C,D):
			con[i] = 2
	
	#ensure the first item is nonzero
	con = con+con
	while not con[0]: con.pop(0)
	con = list(con[0:1440])
	con.append(con[0])
	
	availp = []
	
	while True:
		#print("".join([str(n) for n in con]) + "\n")
		
		n0 = sum(1 for n in con[0:1440] if n==0)
		n1 = sum(1 for n in con[0:1440] if n==1)
		n2 = sum(1 for n in con[0:1440] if n==2)
		#if not n0: break
		
		avail = [None, 720-n1, 720-n2]
		if avail==availp: 1/0
		availp = avail
		#print(avail)
		
		#find the shortest /10+1/ or /20+2/ that can be filled in
		#if none, find the shortest /10+2/ or /20+1/ and fill it with the less populated parent
		
		#(length, start, before)
		#given 1001, it's (2,1,1)
		bestsame = (1440,None,None) # must be /10+1/ or /20+2/
		besthole = (1440,None,None) # can also be /10+2/ or /20+1/
		
		last = -1
		fz = -1
		zeroes = 0
		for i in range(1441):
			c = con[i]
			
			if c == 0:
				if not zeroes:
					fz = i
				
				zeroes += 1
				continue
			
			if zeroes > 0 and zeroes < besthole[0]:
				besthole = (zeroes,fz,last)
			
			if last==c and zeroes > 0 and zeroes < bestsame[0] and avail[c] >= zeroes:
				bestsame = (zeroes,fz,last)
			
			last = c
			zeroes = 0
		
		if bestsame[1]:
			l,s,b = bestsame
			#print(avail,42)
			#print(s,i,b)
			for i in range(l):
				con[s+i] = b
		elif besthole[1]:
			l,s,b = besthole
			
			f = -1
			if avail[1] < avail[2]: f = 1
			else: f = 2
			if not avail[f]: f = 3-f
			
			if avail[f] < l:
				l2 = avail[f]
				if b != f:
					s += (l-l2)
				l = l2
			
			#print(avail)
			#print(s,i,f)
			for i in range(l):
				con[s+i] = f
		else: break # done
	
	switches = 0
	last = con[0]
	for c in con:
		if c==last: continue
		last=c
		switches+=1
	avail = -1
	
	#print(n0,n1,n2)
	
	best = -1
	print("Case #"+str(L+1)+": "+str(switches))










