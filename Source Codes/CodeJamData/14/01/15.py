import sys

def main():
	f = open(sys.argv[1])
	T = int(f.readline().strip())

	for i in range(1,T+1):
		row1 = getRow(f)
		row2 = getRow(f)
		cards = list(row1 & row2)
		if len(cards) == 1:
			print "Case #%d: %s" % (i, cards[0])
		elif len(cards) > 1:
			print "Case #%d: Bad magician!" % i
		else:
			print "Case #%d: Volunteer cheated!" % i
	
def getRow(f):
	n = int(f.readline().strip())
	row = []
	for i in range(1,5):
		l = f.readline()
		if n == i:
			row = set(l.strip().split())
	return row

if __name__ == '__main__':
	main()