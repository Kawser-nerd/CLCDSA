def calc(x,y):
	if y==0:
		return x
	elif x==r:
		return r+y
	elif y==c:
		return r*2+c-x
	elif x==0:
		return r*2+c*2-y
	else:
		return -1
r,c,n=map(int,input().split())
pts=[]
for i in range(n):
	x1,y1,x2,y2=map(int,input().split())
	u,v=calc(x1,y1),calc(x2,y2)
	if u>=0 and v>=0:
		pts.append((u,i))
		pts.append((v,i))
pts=sorted(pts)
stk=[]
for a,b in pts:
	if len(stk)==0 or stk[-1]!=b:
		stk.append(b)
	else:
		stk.pop()
if len(stk):
	print("NO")
else:
	print("YES")