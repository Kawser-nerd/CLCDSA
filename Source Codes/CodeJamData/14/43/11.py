T = int(raw_input())
for tt in range(T):
	ii = raw_input().split(" ")
	W = int(ii[0])
	H = int(ii[1])
	B = int(ii[2])
	result = 0
	river = [[0 for i in xrange(W)] for i in xrange(H)]
	for bb in range(B):
		block = map(int, raw_input().split(" "))
		for xx in range(block[1], block[3]+1):
			for yy in range(block[0], block[2]+1):
				river[xx][yy] = 1
	for xx in reversed(range(W)):
		x = xx
		y = 0
		if river[y][x] == 1:
			continue
		used = []
		while (x < W-1 and river[y][x+1] == 0 and (y,x+1) not in used) or (y<H-1 and river[y+1][x] == 0 and (y+1,x) not in used) or (x > 0 and river[y][x-1] == 0 and (y,x-1) not in used) or (y>0 and river[y-1][x] == 0 and (y-1,x) not in used):
			used += [(y,x)]
			if x < W-1 and river[y][x+1] == 0 and (y,x+1) not in used:
				x = x+1
			elif y<H-1 and river[y+1][x] == 0 and (y+1,x) not in used:
				y = y+1
				if y == H-1:
					result += 1
					for u in used:
						river[u[0]][u[1]]=1
			elif x > 0 and river[y][x-1] == 0 and (y,x-1) not in used:
				x = x-1
			else:
				y = y-1
	print "Case #{0}: {1}".format(str(tt+1), str(result))

	# for ww in reversed(range(W)):
	# 	if used[fi] == 0:
	# 		used[fi] = 1
	# 		for fii in range(fi+1, len(files)):
	# 			if used[fii] == 0 and files[fii]+files[fi]<=diskSize:
	# 				used[fii] = 1
	# 				break
	# 		result += 1
	# print "Case #{0}: {1}".format(str(tt+1), str(result))