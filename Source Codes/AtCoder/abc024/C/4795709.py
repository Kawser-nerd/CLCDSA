N, D, K = map(int,input().split())
LR = [list(map(int,input().split())) for _ in range(D)]
SG = [list(map(int,input().split())) for _ in range(K)]
ABG = []
for k in range(K):
	ABG.append([SG[k][0],SG[k][0],SG[k][1]])

ans = [0 for _ in range(K)]
for d in range(D):
	l,r = LR[d]
	for k in range(K):
		if ans[k] == 0:
			a,b,g = ABG[k]
			if l <= a <= r:
				a = l
			if l <= b <= r:
				b = r
			if a <= g <= b:
				ABG[k] = [a,b,g]
				ans[k] = d+1
			else:
				ABG[k] = [a,b,g]

for k in range(K):
	print(ans[k])