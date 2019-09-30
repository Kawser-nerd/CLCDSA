import sys,operator

readline = sys.stdin.readline
def readstrlist():
	return readline().split()


def readintlist():
	return map (int,readstrlist())


if __name__ == "__main__":
	for i in range(1, int(readline())+1):
		n = int(readline())
		v1 = readintlist()
		v2 = readintlist()
		
		v1.sort()
		v2.sort()
		v2.reverse()
		prod =sum(x[0]*x[1] for x in zip(v1,v2))
		#prod = sum(map(operator.mul,zip (v1,v2)))
		
		print "Case #%d: %d" % (i, prod)
#
