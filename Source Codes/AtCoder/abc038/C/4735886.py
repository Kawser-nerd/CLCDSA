n = int(input())
A = list(map(int,input().split()))
res = 1
tmp = 1
for i in range(1,n):
	if A[i]>A[i-1]:
		tmp += 1
		res += tmp
	else:
		tmp = 1
		res += tmp
print(res)