T = int(raw_input())




def calcbest(bestsofar, stuff, C):
	if stuff == []:
		return bestsofar
	if stuff[0] > bestsofar + 1:
		return bestsofar
	return calcbest(bestsofar + C*stuff[0], stuff[1:], C)

	 

def doprob():
	read = [int(k) for k in raw_input().split()]
	C = read[0]
	D = read[1]
	V = read[2]
	read = [int(k) for k in raw_input().split()]
	read.sort()
	aug = []
	best = calcbest(0, read, C)
	while best < V:
		aug.append(best + 1)
		best = calcbest(0, sorted(read + aug), C)
	return len(aug)

for qq in range(T):
	print "Case #" + str(qq+1) + ": " + str(doprob())