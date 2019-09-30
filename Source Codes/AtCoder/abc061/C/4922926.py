N, K = map(int, input().split())
arr = [list(map(int, input().split())) for i in range(N)]
arr.sort()
 
n = 0
for i in range(N):
	n += arr[i][1]
	if n >= K:
		print(arr[i][0])
		break