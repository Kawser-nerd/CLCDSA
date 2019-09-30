n,m=map(int,input().split())
a=[input() for _ in '1'*n]
b=[input() for _ in '1'*m];
for i in range(n-m+1):
	for j in range(n-m+1):
		c=[a[i+k][j:j+m]for k in range(m)]
		if b==c:print('Yes');exit()
print('No')