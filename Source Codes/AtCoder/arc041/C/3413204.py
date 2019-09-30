n,k = (int(i) for i in input().split())
p,ln,rn,l,r,ans = [],0,0,0,0,0
for _ in range(n):
	x,d = (i for i in input().split())
	p.append((int(x),d=="L"))
if p[0][1]: l = p[0][0]
for i in range(n-1):
	if p[i][1] and p[i+1][1]:
		ln+=1
		ans+=p[i+1][0]-l-ln
	elif p[i][1]:
		ans+=(l-r-1)*max(ln+1,rn)
		ln,rn = 0,0
	elif p[i+1][1]:
		l,r = p[i+1][0],p[i][0]
		rn+=1
	else:
		rn+=1
		ans+=(p[i+1][0]-p[i][0]-1)*rn
if n-1:
	if p[-1][1] and p[-2][1]: ans+=(l-r-1)*max(ln+1,rn)
	elif p[-1][1]: ans+=(p[-1][0]-r-1)*max(rn,1)
	else: ans+=(k-p[-1][0])*(rn+1)
else:
	if p[0][1]: ans = p[0][0]-1
	else: ans = k-p[0][0]
print(ans)