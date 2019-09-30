import sys


if __name__ == "__main__":
	T = int(sys.stdin.readline())

	for t in range(T):
		n,sraw = sys.stdin.readline().split()
		n = int(n)
		shy = [int(c) for c in sraw]
		gap = 0
		psum = 0
		for i in range(n+1):
			if shy[i] != 0:
				gap = max(gap, i-psum)
				psum = psum + shy[i]
		print "Case #{}: {}".format(t+1, gap)