T = input()
for t in range(T):
	B = [raw_input() for i in range(4)]
	raw_input()
	
	L = B
	for i in range(4):
		L += ["".join(B[x][i] for x in range(4))]
	L += [B[0][0]+B[1][1]+B[2][2]+B[3][3]]
	L += [B[3][0]+B[2][1]+B[1][2]+B[0][3]]
	
	ans = "Game has not completed"
	for p in "OX":
		for l in L:
			if l.count(p)==4 or l.count(p)==3 and l.count("T")==1:
				ans = p+" won"
	if ans=="Game has not completed" and "." not in "".join(B):
		ans = "Draw"
	
	print "Case #%s: %s"%(t+1,ans)
