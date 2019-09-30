def solve_easy(r,y,b):
	x=[r,y,b]
	cols=['R','Y','B']
	tot = r+y+b
	for i in xrange(3):
		if(x[i]*2>tot):
			return 'IMPOSSIBLE'
	best = max(range(3),key=lambda i: x[i])
	ans=[cols[best]]*x[best]
	rs=[xrange(len(ans)), xrange(len(ans)-1,-1,-1)]
	rat=-1
	for i in xrange(3):
		if(i==best):
			continue
		rat +=1
		ran = rs[rat]
		for j in ran:
			if (x[i] > 0):
				ans[j]=ans[j]+cols[i]
				x[i] -=1
			else:
				break

	return ''.join(ans)

def ins_after(s, t, at):
	return s[:at]+t+s[at:]

def solve(n,r,o,y,g,b,v):
	x=[r,y,b]
	l=[g,v,o]
	cols=['R','Y','B']
	offs=['GR','VY','OB']
	tot = r+y+b+g+v+o
	for i in xrange(3):
		if(l[i] > x[i]):
			return 'IMPOSSIBLE'
		if(l[i] == x[i] > 0):
			for j in xrange(3):
				if j==i:
					continue
				if(l[j]+x[j] > 0):
					return 'IMPOSSIBLE'
			return offs[i]*l[i]
	z = [x[i]-l[i] for i in xrange(3)]
	ans = solve_easy(*z)
	if(ans == 'IMPOSSIBLE'):
		return 'IMPOSSIBLE'
	for i in xrange(3):
		if(l[i]>0):
			at=ans.find(cols[i])
			ans = ins_after(ans,offs[i]*l[i],at+1)
	return ans



T = int(input())
for case in range(1,T+1):
	n,r,o,y,g,b,v=map(int,raw_input().split())
	print("Case #{}: {}".format(case, solve(n,r,o,y,g,b,v)))
