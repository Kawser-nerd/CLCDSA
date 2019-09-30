T = int(raw_input())

def f1(C, W):
	return C/W

def f2(C, W):
	if C == W:
		return W
	if C <= 2*W:
		return W+1
	else:
		return 1 + f2(C-W, W)

def doprob():
	read = raw_input()
	read = [int(k) for k in read.split()]
	R = read[0]
	C = read[1]
	W = read[2]
	return str((R-1)*f1(C,W) + f2(C,W))

for qq in range(T):
	print "Case #" + str(qq+1) + ": " + str(doprob())