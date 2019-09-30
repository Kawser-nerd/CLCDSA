from collections import defaultdict

N = int(input())
R = [0] * N
H = [0] * N
maxR = 0
for i in range(N):
	R[i],H[i] = map(int,input().split())
	maxR = max(maxR, R[i])

rank = [[] for _ in range(maxR + 1)]
for i in range(N):
	rank[R[i]] += [i]

cum_sum = [0] * (maxR + 1)
for i in range(0, maxR + 1):
	if i == 0:
		cum_sum[i] = len(rank[i])
	else:
		cum_sum[i] = cum_sum[i-1] + len(rank[i])

res = [[0]*3 for _ in range(N)]
for i in range(1, maxR + 1):
	cnt = defaultdict(int)
	for j in range(len(rank[i])):
		cnt[H[rank[i][j]]] += 1
	win = cum_sum[i-1]
	lose = N - cum_sum[i]
	draw = 0
	for j in range(len(rank[i])):
		index = rank[i][j]
		hand = H[index]
		w, l, d = 0, 0, 0
		if hand == 1:	# ??
			w = cnt[2]
			l = cnt[3]
			d = cnt[1] - 1			
		elif hand == 2: # ???
			w = cnt[3]
			l = cnt[1]
			d = cnt[2] - 1
		else: # if hand == 3: # ??
			w = cnt[1]
			l = cnt[2]
			d = cnt[3] - 1
		res[index][0] = win + w
		res[index][1] = lose + l
		res[index][2] = draw + d

for i in range(N):
	print(res[i][0],res[i][1], res[i][2])