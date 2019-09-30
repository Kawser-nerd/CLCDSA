import sys
import math

def gcd(a,b):
	if (a<0):
		return gcd(-a, b)
	if (b<0):
		return gcd(a, -b)
	if (a<b):
		return gcd(b, a)
	if (b==0):
		return a
	return gcd(b, a%b)

def mxcoord(W, H, X0, Y0, X1, Y1):
	mx = 1000000000
	if X1>0:
		mx = min(mx, (W-1-X0) / X1)
	elif X1<0:
		mx = min(mx, X0/(-X1))
	if Y1>0:
		mx = min(mx, (H-1-Y0) / Y1)
	elif Y1<0:
		mx = min(mx, Y0/(-Y1))
	return mx
	
def points(W, H, X0, Y0, X1, Y1):
	return mxcoord(W, H, X0, Y0, X1, Y1)+1
	
def firstp(W, H, X0, Y0, X1, Y1):
	m1 = max(0, -mxcoord(W, H, X0, Y0, -X1, -Y1))
	m2 = mxcoord(W, H, X0, Y0, X1, Y1)
	if m2>=m1:
		return (X0+X1*m1, Y0+Y1*m1)
	return None

def solve1d(W, H, X1, Y1, X2, Y2, X0, Y0):
	G = gcd(X1, Y1)
	X3 = X1/G
	Y3 = Y1/G
	sums = [0]*G
	S = 0
	if (X3!=0):
		S = X2/X3
	else:
		S = Y2/Y3
	res = 0;
	while True:
		cnt = points(W, H, X0, Y0, X1, Y1)
		sums[res] = max(sums[res], cnt)
		X0 += X2
		Y0 += Y2
		res = (res+S)%G
		if not(X0>=0 and Y0>=0 and X0<W and Y0<H):
			break
	s = 0
	for x in sums:
		s += x
	return s	

def do_test(input):
	line = input.readline().split(' ')
	W = int(line[0])
	H = int(line[1])
	line = input.readline().split(' ')
	X1 = int(line[0])
	Y1 = int(line[1])
	line = input.readline().split(' ')
	X2 = int(line[0])
	Y2 = int(line[1])
	line = input.readline().split(' ')
	X0 = int(line[0])
	Y0 = int(line[1])
	if X1*Y2-X2*Y1==0:
		return str(solve1d(W, H, X1, Y1, X2, Y2, X0, Y0))
	sum = 0
	while True:
		pts = points(W, H, X0, Y0, X1, Y1)
		sum += pts
		Xn = X0 + X2
		Yn = Y0 + Y2
		n = firstp(W, H, Xn, Yn, X1, Y1)
		if n is None:
			break
		Xn = n[0]
		Yn = n[1]
		X0 = Xn-X2
		Y0 = Yn-Y2
		if not(X0>=0 and Y0>=0 and X0<W and Y0<H):
			break
		X0 = Xn
		Y0 = Yn
		if not(X0>=0 and Y0>=0 and X0<W and Y0<H):
			break
	
	return str(sum)

input = sys.stdin

N = int(input.readline())

for test in range(N):
	answer = do_test(input)
	print 'Case #%(case)d: %(answer)s' % \
		{'case': test+1, 'answer': answer}
	sys.stdout.flush()
