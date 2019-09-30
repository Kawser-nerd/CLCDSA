N,M = list(map(int,input().split(' ')))
 
if M % N == 0:
	print(M//N)
	exit()

ans = 1
for i in range(2,100000+1):
	k = M % i
	if k == 0:
		j = M//i
		if i >= N and j >= N:
			ans = max(ans,i,j)
		elif i >= N:
			ans = max(ans,j)
		elif j >= N:
			ans = max(ans,i)
print(ans)