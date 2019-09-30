import numpy as np

inname = "input.txt"
outname = "output.txt"

with open(inname, 'r') as f:
	cases = int(f.readline())
	for tc in range(1,cases+1):
		line = f.readline().strip().split(' ')
		N = int(line[0])
		P = int(line[1])
		Pi = []
		R = [0]*P
		line = f.readline().strip().split(' ')
		for i in range(N):
			Pi.append(int(line[i]))
			R[Pi[i] % P] += 1

		ans = 0
		if P == 2:
			ans = R[0] + (R[1]+1)//2
		elif P == 3:
			ans = R[0]
			if R[1] < R[2]:
				a = R[1]
				b = R[2]
			else:
				a = R[2]
				b = R[1]
			ans += a
			b -= a
			ans += (b+2)//3
		else:
			ans = R[0]
			if R[1] < R[3]:
				a = R[1]
				b = R[3]
			else:
				a = R[3]
				b = R[1]
			c = R[2]
			ans += c//2
			c %= 2
			ans += a
			b -= a
			if c==1 and b>=2:
				c -= 1
				b -= 2
				ans += 1
			ans += b//4
			b %= 4
			if c+b > 0:
				ans += 1


		print("Case #%d: %d" % (tc, ans))
