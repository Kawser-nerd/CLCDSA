import sys
input = sys.stdin

def solve(input):
	xs = input.readline().split(' ')
	x1 = int(xs[0])
	y1 = int(xs[1])
	x2 = int(xs[2])
	y2 = int(xs[3])
	x3 = int(xs[4])
	y3 = int(xs[5])
	xs = input.readline().split(' ')
	x1n = int(xs[0])
	y1n = int(xs[1])
	x2n = int(xs[2])
	y2n = int(xs[3])
	x3n = int(xs[4])
	y3n = int(xs[5])
	
	a11 = x2-x1-x2n+x1n
	a12 = x3-x1-x3n+x1n
	a21 = y2-y1-y2n+y1n
	a22 = y3-y1-y3n+y1n
	b1 = x1n-x1
	b2 = y1n-y1
	D = a11*a22-a12*a21
	Da = b1*a22-a12*b2
	Db = a11*b2-a21*b1
	alpha = Da*1./D
	beta = Db*1./D
	cx = x1+alpha*(x2-x1)+beta*(x3-x1)
	cy = y1+alpha*(y2-y1)+beta*(y3-y1)
	return str(cx)+' '+str(cy)

N = int(input.readline())

for i in range(N):
	res = solve(input)
	print 'Case #'+str(i+1)+': '+res

