from bisect import bisect_left,bisect
n,l,t = (int(i) for i in input().split())
x,y,c = [[int(i) for i in input().split()]],[0],0
ans = [(x[0][0]-t)%l if x[0][1]-1 else (x[0][0]+t)%l]
ans2 = ans[0]
for _ in range(n-1):
	a,b = (int(i) for i in input().split())
	x.append([a,b])
	if b!=x[0][1]: c+=1
	y.append(c)
	if b-1: ans.append((a-t)%l)
	else: ans.append((a+t)%l)
ans.sort()
if x[0][1]-1: ans3 = bisect_left(ans,ans2)
else: ans3 = bisect(ans,ans2)-1
num = int(t/(l/2))
if x[0][1]-1:
	p = (-(t-num*(l/2))*2+x[0][0])%l
	d = (y[-1]*num+y[-1]-y[bisect_left(x,[p,0])-1])%n
else:
	p = ((t-num*(l/2))*2+x[0][0])
	d = (y[-1]*num+y[bisect_left(x,[p,3])-1])%n
if x[0][1]-1: d = -d
for i in range(n): print(ans[(ans3-d+i)%n])