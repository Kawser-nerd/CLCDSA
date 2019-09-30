N=int(input())

ans = "No"

for i in range(0, N+1, 7):
	if (N-i)%4 == 0:
		ans = "Yes"

print(ans)