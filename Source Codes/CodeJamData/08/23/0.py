import sys

def getLine():
	global fin
	line = fin.readline()
	if line[-1]=="\n":
		line = line[:-1]
	return line


def solve():
	k = int(getLine())
	d = map(int,getLine().split(" "))
	assert (len(d)-1 == d[0])
	d = d[1:]

	deck = [k]
	for i in range(1,k):
		pos = k%(i+1)
#		print pos
		if pos == 0:
			deck = [k-i] + deck
		else:
			deck = deck[-pos:]+[k-i]+deck[:-pos]
#		print deck

#	print deck

	return " ".join(str(deck[x-1]) for x in d)

#########
if len(sys.argv) != 2:
	print "Specify input file"
	exit(1)

fin = open(sys.argv[1])


n = int(getLine())

fout = open("out","wt")

for i in range(1,n+1):
	print "Solving",i
	fout.write("Case #%s: "%i)
	fout.write(solve())
	fout.write("\n")

fout.close()