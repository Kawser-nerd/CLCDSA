n=int(input())
h=list(map(int, input().split()))

ans = 0
for cheight in range(101):
	renz = False
	for x in range(n):
		if h[x] > cheight:
			if not renz:
				renz = True
				ans += 1
		else:
			renz = False

print(ans)