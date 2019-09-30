for tc in range(1, int(input())+1):
	A = input()
	N = len(A)
	ans = ""
	for i in range(N):
		pans = ""
		for d in range(0, 10):
			d = str(d)
			if int (ans + d * (N-i)) <= int(A): pans = ans + d
		ans = pans
	print ("Case #%d: %d"%(tc, int(ans)))
