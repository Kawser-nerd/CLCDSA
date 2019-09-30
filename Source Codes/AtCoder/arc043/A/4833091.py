n,a,b = map(int,input().split())
S = [int(input()) for i in range(n)]
S.sort()
ave = sum(S)/n
d = S[-1]-S[0]
if d == 0:
	if b != d:
		print(-1)
	else:
		print(1,a-ave)
else:
	p = b/d
	print(p,a-p*ave)