n = int(input())
A = list(map(int, input().split()))

dp = 1
for a in A:
	dp |= dp<<a

for i in range((sum(A)+1)//2, sum(A)+1):
	if (dp>>i)%2 == 1:
		print(i)
		break