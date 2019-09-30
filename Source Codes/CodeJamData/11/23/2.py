#!/usr/bin/python

T = int(raw_input())

def valid(m, room, colors):
	mm = {}
	for x in room:
		if x in m and m[x] != -1:
			mm[m[x]] = True
	return len(mm) == colors

def solve(m, rooms, rc, rr, colors, n, i):
	if i == n:
		if all([valid(m, rooms[x], colors) and not any(rc[x]) for x in xrange(len(rooms))]):
			return m
		else:
			return None
	else:
		#print "\t",m,rooms,remaining
		for c in xrange(colors):
			m[i] = c
			addto = [x for x in xrange(len(rooms)) if rc[x][c]]
			hasroom = [x for x in xrange(len(rooms)) if rr[x][i]]
			for a in addto:
				rc[a][c] = False
			for h in hasroom:
				rr[h][i] = False
			if all([valid(m, rooms[x], colors) for x in xrange(len(rooms)) if (x in addto and not any(rr[x]))]):
				tmp = solve(m, rooms, rc, rr, colors, n, i+1)
				if tmp:
					return tmp
			for a in addto:
				rc[a][c] = True
			for h in hasroom:
				rr[h][i] = True
			m[i] = -1
		return None
	

for nCase in xrange(1, T+1):
	N,M = map(int, raw_input().strip().split())
	
	U = map(lambda x: int(x)-1, raw_input().strip().split())
	V = map(lambda x: int(x)-1, raw_input().strip().split())
	
	rooms = [range(N)]
	
	for i in xrange(M):
		for r in rooms:
			if U[i] in r and V[i] in r:
				rooms.remove(r)
				u = r.index(U[i])
				v = r.index(V[i])
				
				if u < v:
					rooms.append(r[:u+1] + r[v:])
					rooms.append(r[u:v+1])
				else:
					rooms.append(r[:v+1] + r[u:])
					rooms.append(r[v:u+1])
				
				break
	
	colors = min(map(len, rooms))
	
	for c in xrange(colors, 2, -1):
		tmp = solve({}, rooms, [range(c) for x in rooms], [[i in x for i in xrange(N)] for x in rooms], c, N, 0)
		if tmp:
			print "Case #%d: %d" % (nCase, c)
			print " ".join([str(tmp[i]+1) for i in xrange(N)])
			break
