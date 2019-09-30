# -*- coding: utf-8 -*-




from collections import defaultdict as dd



def colourings(N,F):
	coling = [0 for i in range(N)]
	has = [False for i in range(F)]
	while True:
		for f in range(F): has[f] = False
		for f in coling: has[f] = True
		hasall = True
		for h in has:
			if not h:
				hasall = False
				break
		if hasall:
			yield tuple(coling)
		coling[0] += 1
		done = False
		for i in range(N):
			if coling[i] is F:
				#if i==4: print coling
				if i==N-1:
					done = True
					break
				coling[i] = 0
				coling[i+1] += 1
		if done: break



T = int(raw_input())

for t in range(1,1+T):
	
	N,M = [int(w) for w in raw_input().split()]
	ws = [int(w)-1 for w in raw_input().split()]
	we = [int(w)-1 for w in raw_input().split()]
	walls = zip(ws,we)
	
	rooms = [ tuple(range(N)) ]
	for wall in walls:
		for ri,room in enumerate(rooms):
			if wall[0] in room and wall[1] in room:
				si = room.index(wall[0])
				ei = room.index(wall[1])
				si,ei = min(si,ei),max(si,ei)
				mid = tuple(room[si:ei+1])
				out = tuple(room[ei:]+room[:si+1])
				del rooms[ri]
				rooms.append(mid)
				rooms.append(out)
				break
	
	roomsforv = dd(list)
	for room in rooms:
		for v in room:
			roomsforv[v].append(room)
	
	smallest = min([len(r) for r in rooms])
	
	#print 'Rooms:'
	#for room in rooms:
		#print room
	#print
	
	bflavs = []
	bn = -1
	for n in range(1,smallest+1):
		#print n
		worked = False
		for flavs in colourings(N,n):
			#print 'Trying',flavs
			okay = True
			roomhas = dd(set)
			for v,f in enumerate(flavs):
				for r in roomsforv[v]:
					roomhas[r].add(f)
			for r in rooms:
				if len(roomhas[r])!=n:
					okay = False
					break
			if not okay:
				continue
			else:
				bflavs = flavs
				bn = n
				worked = True
				break
		if not worked:
			break
	
	print 'Case #{x}: {C}'.format(x=t,C=bn)
	print ' '.join([str(f+1) for f in bflavs])





















