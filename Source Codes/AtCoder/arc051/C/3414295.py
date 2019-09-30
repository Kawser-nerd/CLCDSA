n,a,b = (int(i) for i in input().split())
x = [int(i) for i in input().split()]
x,y,c,mod = sorted(x),[],0,10**9+7
if a-1:
	for i in x:
		m = i
		while m*a<x[-1]:
			m*=a
			c+=1
		y.append(m)
	if b<=c:
		for i in range(b):
			x[0]*=a
			x.sort()
		for i in x: print(i)
	else:
		d,e,y = (b-c)//n,(b-c)%n,sorted(y)
		for i in range(e): y[i] = (y[i]*pow(a,d+1,mod))%mod
		for i in range(e,n): y[i] = (y[i]*pow(a,d,mod))%mod
		for i in y[e:]+y[:e]: print(i)
else:
	for i in x: print(i)