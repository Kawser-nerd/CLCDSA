testCount = int(raw_input())
for testIndex in range(testCount):
	ans = "Case #" + str(testIndex+1) + ": "
	n,mx,my = [int(x) for x in raw_input().split(" ")]
	ss = [int(x) for x in raw_input().split(" ")]
	s = []
	for i,a in enumerate(ss):
		s += [[i, a]]
		
	s.sort(key=lambda x:-x[1])
	p = [[0,0]] * n
	
	cx, cy = 0,0
	ny = 0
	for i,l in s:
		if cx > 0:
			cx += l
		if cx > mx:
			cx = 0
			cy = ny + l
		if cy > my:
			print "BUG!!!!!!!!!!!!!!!!!!!!!!!!!!"
		p[i] = cx,cy
		if cx == 0:
			ny = cy + l
		cx += l
		
	for i in p:
		ans += str(i[0]) + " " + str(i[1]) + " "
	
	print (ans )
