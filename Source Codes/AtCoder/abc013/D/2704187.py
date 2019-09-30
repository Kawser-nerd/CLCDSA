n,m,d = (int(i) for i in input().split())
a = [int(i) for i in input().split()]
b = [i for i in range(n+1)]
for i in a: b[i],b[i+1] = b[i+1],b[i]
x,y,ans = [0 for i in range(n+1)],[True for i in range(n+1)],[0 for i in range(n+1)]
for i in range(1,n+1): x[b[i]] = i
for i in range(1,n+1):
	if y[i]:
		z,now = [],i
		while True:
			if y[now]:
				z.append(now)
				y[now],now = False,x[now]
			else: break
		num,lz = d%len(z),len(z)
		for i in range(lz): ans[z[i]] = z[(i+num)%lz]
for i in ans[1:]: print(i)