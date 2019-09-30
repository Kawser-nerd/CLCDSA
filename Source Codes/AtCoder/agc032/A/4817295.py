N = int(input())
arr = list(map(int, input().split()))
 
ans = []
 
for idx1 in range(1, N+1):
	for idx2 in range(len(arr), 0, -1):
		if arr[idx2-1] == idx2:
			tmp = arr.pop(idx2-1)
			ans.append(tmp)
			break
		elif idx2 == 1:
			print(-1)
			exit()

for idx in range(0, N):
	tmp = ans.pop(-1)
	print(tmp)