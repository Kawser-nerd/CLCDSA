a,b = map(int,input().split())
L = list(map(int,input().split()))
R = list(map(int,input().split()))
cnt = 0
for l in L:
	if l in R:
		cnt += 1
		R.remove(l)
print(cnt)