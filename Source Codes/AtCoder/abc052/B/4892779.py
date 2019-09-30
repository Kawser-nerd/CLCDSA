N = int(input())
S = input()

x = 0
ans = 0
for i in range(N):
	if S[i:i+1]=='I':
		x += 1
		ans = max(ans, x)
	elif S[i:i+1]=='D':
		x -= 1

print(ans)