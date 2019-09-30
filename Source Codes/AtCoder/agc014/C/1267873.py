H, W, K = list(map(int, input().split()))
MAP = []
for i in range(H):
	MAP.append(list(input()))
for i in range(H):
	for j in range(W):
		if MAP[i][j] == "S":
			h = i
			w = j
			MAP[i][j] = ","
			break
		else:
			pass
length = min([h, w, H - h - 1, W - w - 1])
abl = [[h, w]]
for j in range(K):
	ln = len(abl)
	abll = []
	for i in range(ln):
		if MAP[abl[i][0] + 1][abl[i][1]] == ".":
			if abl[i][0] + 1 == H - 1:
				length = 0
				break
				break
			else:
				if H - abl[i][0] - 2 < length:
					length = H - abl[i][0] - 2
				else:
					pass
				abll.append([abl[i][0] + 1, abl[i][1]])
				MAP[abl[i][0] + 1][abl[i][1]] = ","
		else:
			pass

		if MAP[abl[i][0] - 1][abl[i][1]] == ".":
			if abl[i][0] - 1 == 0:
				length = 0
				break
				break
			else:
				if abl[i][0] - 1 < length:
					length = abl[i][0] - 1
				else:
					pass
				abll.append([abl[i][0] - 1, abl[i][1]])
				MAP[abl[i][0] - 1][abl[i][1]] = ","
		else:
			pass

		if MAP[abl[i][0]][abl[i][1] + 1] == ".":
			if abl[i][1] + 1 == W - 1:
				length = 0
				break
				break
			else:
				if W - abl[i][1] - 2 < length:
					length = W - abl[i][1] - 2
				else:
					pass
				abll.append([abl[i][0], abl[i][1] + 1])
				MAP[abl[i][0]][abl[i][1] + 1] = ","

		if MAP[abl[i][0]][abl[i][1] - 1] == ".":
			if abl[i][1] + 1 == 0:
				length = 0
				break
				break
			else:
				if abl[i][1] - 1 < length:
					length = abl[i][1] - 1
				else:
					pass
				abll.append([abl[i][0], abl[i][1] - 1])
				MAP[abl[i][0]][abl[i][1] - 1] = ","
	abl = abll
if length % K == 0:
	print(int(length // K) + 1)
else:
	print(int(length // K) + 2)