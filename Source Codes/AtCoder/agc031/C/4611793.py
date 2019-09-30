def Double(vec):
	m=len(vec)
	res=[]
	for i in range(0,m,2):
		res.extend([vec[i],vec[i]^m,vec[i+1]^m,vec[i+1]])
	return res

def Greedy(n):
	m=1<<n
	res=[0]*m
	vis=[False]*m
	vis[0]=True
	for i in range(1,m):
		x=res[i-1]
		for j in range(n):
			if not vis[x^(1<<j)]:
				x^=1<<j
				break
		vis[x]=True
		res[i]=x
	return res

def Perfect(n):
	if n==1:
		return [0,1]
	m=1<<n
	A=Greedy(n-1)
	B=Double(Perfect(n-2))
	B.reverse()
	for i in range(m>>1):
		B[i]^=m-1
	A.extend(B)
	return A

n,a,b=map(int,input().split())
m=1<<n
c=bin(a^b).count('1')
if not c&1:
	print('NO')
	exit()
tmp=Perfect(c)
for i in range(c,n):
	tmp=Double(tmp)
p=0
q=c
ans=[0]*m
for i in range(n):
	if (a^b)>>i&1:
		for j in range(m):
			ans[j]^=(((tmp[j]>>p)^(a>>i))&1)<<i
		p+=1
	else:
		for j in range(m):
			ans[j]^=(((tmp[j]>>q)^(a>>i))&1)<<i
		q+=1
print('YES\n',' '.join(str(i) for i in ans),sep='')