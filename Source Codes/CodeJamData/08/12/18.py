import sys

readline = sys.stdin.readline
def readstrlist():
	return readline().split()

def readintlist():
	return map (int,readstrlist())

def solve (clis,N):
	R = [None]*N
	rp = []
	while R != rp:
		rp = R*1
		for fl in range(len(R)):
			#print fl,R,clis
			
			if R[fl] == None:
				if [(fl+1,1)] in clis:
					R[fl] = 1
					for cli in range(len(clis)):
						clis[cli] = list(pref for pref in clis[cli] if pref!=(fl+1,0))
					#print fl,clis
				elif [(fl+1,0)] in clis:
					R[fl] = 0
					for cli in range(len(clis)):
						clis[cli] = list(pref for pref in clis[cli] if pref!=(fl+1,1))
					#print fl,clis
			
			#print 'quita', (fl+1,R[fl])
			clis = list(x for x in clis if (fl+1,R[fl]) not in x)
	
			if not all (clis):
				return "IMPOSSIBLE"
			
	return ' '.join(map(str,((x or 0) for x in R)))

if __name__ == "__main__":
	for i in range(1, int(readline())+1):
		N = int(readline())
		R = [None]*N
		M = int(readline())
		clis = []
		for j in range (M):
			l = readintlist()
			T = l[0]
			clis.append (list((l[x], l[x+1]) for x in range(1,len(l),2)))
		
		#print i
		print "Case #%d: %s" % (i, solve (clis,N))
		

