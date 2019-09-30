import sys

def readg():
	while True:
		line = sys.stdin.readline()
		if line == "":
			return
		tokens = line.strip().split()
		for i in tokens:
			try:
				i = int(i)
			except:
				pass
			yield i

input = readg()
read = input.next

def readm(n):
	for i in range(n):
		yield read()


t = input.next()

def solve():
	n,d = readm(2)
	x = []
	for _ in range(n):
		x += [list(readm(2))] 

	def dasie(t):
		mp = -2000000000
		for p,v in x:
			np = max(mp, p-t)
			if np+d*(v-1) > p+t:
#				print "NIE"
				return False
			mp = np+d*v
#			print mp,
#		print "TAK"
		return True
	
	a = 0.0
	b = 1000000000000.0

	while b-a > 1e-7:
		s = (a+b)/2
		if dasie(s):
			b = s
		else:
			a = s

	if a<0.0000001:
		return 0
	return (a+b)/2

for i in range(t):
	print "Case #{}: {}".format(i+1, solve())
