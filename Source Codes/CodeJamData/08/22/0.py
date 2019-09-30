import sys

def getLine():
	global fin
	line = fin.readline()
	if line[-1]=="\n":
		line = line[:-1]
	return line


part = []

def representative(x):
	if part[x]==x:
		return x
	res = representative(part[x])
	part[x] = res
	return res


def union(x,y):
#	print "union",x,y
	x = representative(x)
	y = representative(y)
	part[x] = y


def primes(upTo):
	if upTo<2:
		return []
	res = [2]
	for i in range(3,upTo+1,2):
		if all(i%p!=0 for p in res):
			res.append(i)
	return res

def solve():
	global part
	a,b,p = map(int,getLine().split())
	part = range(b-a+1)
	pr = primes(b+1)


	
	for f in pr:
		if f>=p:
			for i in range((a+f+f-1)/f*f,b+1,f):
				union(i-f-a,i-a)

	s = set()
	for i in range(len(part)):
		s.add(representative(i))

#	print part
#	print s

	return str(len(s))

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