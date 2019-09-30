N=int(input())
A=list(map(int, input().split()))

ans=0
for x in A:
	for y in A:
		ans=max(abs(y-x), ans)

print(ans)