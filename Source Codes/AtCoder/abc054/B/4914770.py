N,M=map(int,input().split())
A=[input() for i in range(N)]
B=[input() for i in range(M)]
flag=0
for i in range(N-M+1):
	for j in range(N-M+1):
		for k in range(M):
			if A[i+k][j:j+M]!=B[k]:
				break
		else:
			flag=1
print('Yes' if flag else 'No')