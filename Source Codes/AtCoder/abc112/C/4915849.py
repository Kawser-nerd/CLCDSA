N=int(input())
xyh=sorted([list(map(int, input().split())) for _ in range(N)], key=lambda x: x[2], reverse=True)

def find(cx, cy, H):
	for x,y,h in xyh:
		if h != max(H-abs(x-cx)-abs(y-cy), 0):
			return False
	return True

def solve():
	for cx in range(101):
		for cy in range(101):
			x,y,h = xyh[0]
			H = h + abs(x-cx) + abs(y-cy)
			if find(cx, cy, H):
				return "%d %d %d" % (cx, cy, H)
	raise Exception

print(solve())