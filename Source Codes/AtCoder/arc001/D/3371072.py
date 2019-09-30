from itertools import combinations
x,y,c,d,e,f = [],[],[],[],[],1
for i in range(8):
	s = input()
	if s.count("Q")>1: f = 0
	elif "Q" in s:
		n = s.find("Q")
		x.append(i-n)
		y.append(i+n)
		c.append(n)
		d.append(i)
		e.append([i,n])
if any(len(set(i))!=3 for i in [x,y,c]): f = 0
if f:
	def ok(q):
		qx,qy,qc,qd = [],[],[],[]
		for i,j in q:
			qx.append(i-j)
			qy.append(i+j)
			qc.append(j)
			qd.append(i)
		qx,qy,qc,qd = qx+x,qy+y,qc+c,qd+d
		return all(len(set(i))==8 for i in [qx,qy,qc,qd])	
	c2,d2,e2 = [],[],[]
	for i in range(8):
		if i not in c: c2.append(i)
		if i not in d: d2.append(i)
	for i in c2:
		for j in d2: e2.append([j,i])
	for i in combinations(e2,5):
		if ok(i):
			f = 1
			break
		else: f = 0
	if f:
		ans = sorted(list(i)+e)
		for i,j in ans: print("."*j+"Q"+"."*(7-j))
	else: print("No Answer")
else: print("No Answer")