
# python 3.0





Infinity = 1e10000




bests = {}


def best(qs=[0,1]):
	base = qs[-1] - qs[0] - 2	# number of cells in between, minus newly empty cell
	if len(qs)==2:
		return 0
	elif len(qs)==3:
		return base
	else:
		key = tuple(qs)
		if key not in bests:
			b = Infinity
			for split in range(1,len(qs)-1):
				b = min(b , best(qs[:split+1])+best(qs[split:]) )
			bests[key] = b+base
		return bests[key]



N = int(input())

for case in range(1,N+1):
	
	line = input().split()
	P = int(line[0])
	Q = int(line[1])
	pris = [int(w) for w in input().split()]
	
	cells = [0] +pris+ [P+1]
	#print(cells)
	ans = best(cells)
	
	print("Case #"+str(case)+": "+str(ans))

