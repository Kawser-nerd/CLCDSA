n = int(input())
p,x,y = [],[],[]
for _ in range(n):
	a,b = (int(i) for i in input().split())
	p.append([a,b])
	x.append(a+b)
	y.append(a-b)
a1,a2,b1,b2 = max(x),min(x),max(y),min(y)
if a1-a2==b1-b2: print(((a1+a2)//2+(b1+b2)//2)//2,((a1+a2)//2-(b1+b2)//2)//2)
else:
	d = max(a1-a2,b1-b2)
	x2,y2 = [a1-d//2,d//2+a2],[b1-d//2,d//2+b2]
	for i in x2:
		for j in y2:
			I,J = (i+j)//2,(i-j)//2
			num = abs(p[0][0]-I)+abs(p[0][1]-J)
			if all(abs(k-I)+abs(k2-J)==num for k,k2 in p): X,Y = I,J
	print(X,Y)