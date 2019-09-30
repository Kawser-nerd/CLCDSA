n,m = map(int,input().split())
L = [input() for i in range(m)]
A = set()
for l in reversed(L):
	if l not in A:
		print(l)
		A.add(l)
for i in range(1,n+1):
	if str(i) not in A:
		print(str(i))