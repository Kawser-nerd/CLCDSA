n = int(input())
x,y,ans = [],[],0
for _ in range(n):
	a,b = (int(i) for i in input().split())
	if a<b: x.append((a,b))
	else: y.append((b,a))
x,y,m = sorted(x),sorted(y)[::-1],0
for i,j in x:
	m+=i
	ans,m = max(ans,m),m-j
for i,j in y:
	m+=j
	ans,m = max(ans,m),m-i
print(ans)