n,k = map(int,input().split())
T = [int(input()) for i in range(n)]
for i in range(2,n):
	sleep = T[i]+T[i-1]+T[i-2]
	if sleep < k:
		print(i+1)
		exit()
print(-1)