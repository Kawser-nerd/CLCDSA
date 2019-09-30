import sys

MAX=10000000

class hdict(dict):
	def __key(self):
		return tuple((k,self[k]) for k in sorted(self))
	def __hash__(self):
		return hash(self.__key())
	def __eq__(self, other):
		return self.__key() == other.__key()

def free(p, cave, hd):
	return cave[p[0]][p[1]] == '.' or hd.has_key((p[0], p[1]))

N = int(sys.stdin.readline())
for case in range(N):
	print "Case #%d:" % (case+1),
	(R,C,F) = map(int,sys.stdin.readline().split(' '))
	cave=[]
	for r in range(R):
		cave.append(sys.stdin.readline().rstrip());

	D = {}
	st0 = (0,0, hdict())
	D[st0] = 0
	st = []
	st.append(st0)
	dr = (0, 0, 1, 1)
	dc = (-1, 1, -1, 1)
	dig = (False, False, True, True)
	while len(st) > 0:
		fall = -1
		p = st.pop(0)
#		print D
#		print p
		for r in range(len(dr)):
#			print '=>', r
			pp = (p[0] + dr[r], p[1] + dc[r], hdict(p[2]))
			if pp[1] < 0 or pp[1] >= C or pp[0] < 0 or pp[0] >= R:
				continue
			dist = D[p] + dr[r];
			if not dig[r] and free(pp, cave, pp[2]):
				fall = pp[0]
				while fall < R-1 and free((fall+1, pp[1]), cave, pp[2]):
				 	fall += 1
#					print fall
				if fall - pp[0] > F:
					fall = -1
					continue
				if fall == R-1:
					break
				newstate = (fall, pp[1], pp[2])
				if  D.get(newstate, MAX) <= dist:
					continue 
#				print "=> newstate", newstate
				D[newstate] = dist
				st.insert(0, newstate)
			elif dig[r] and not free(pp, cave, pp[2]) and free((pp[0]-1, pp[1]), cave, pp[2]):
				pp[2][(pp[0], pp[1])] = 1
				newstate = (p[0], p[1], pp[2])
				if  D.get(newstate, MAX) <= dist:
					continue 
#				print "+> newstate", newstate
				D[newstate] = dist
				st.append(newstate)
		if fall == R-1:
			break
	
#	print pp		
	if fall == R-1:
		print "Yes %d" % dist
	else:
		print "No"
		
			