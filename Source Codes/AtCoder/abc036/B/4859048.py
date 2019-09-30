n=int(input())
s=[list(input()) for _ in range(n)]
a=[]
for i in range(n):
	tmp=[]
	for j in range(n):
		tmp.append(s[n-j-1][i])
	a.append(tmp)
for i in range(n):
	print(''.join(a[i]))