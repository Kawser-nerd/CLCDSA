N = int(input())
points = []
for _ in range(N):
	x,y = map(int,input().split())
	points.append((x,y))

rotated = [(x + y, x - y) for x, y in points]

xs = [x for (x, y) in rotated]
ys = [y for (x, y) in rotated]

dx = max(xs) - min(xs)
dy = max(ys) - min(ys)
D = max(dx,dy)

p1 = (min(xs) + D // 2, min(ys) + D // 2)
p2 = (min(xs) + D // 2, max(ys) - D // 2)
p3 = (max(xs) - D // 2, min(ys) + D // 2)
p4 = (max(xs) - D // 2, max(ys) - D // 2)

res = []
for x, y in [p1, p2, p3, p4]:
	px,py = (x + y) // 2, (x - y) // 2
	if len(set([abs(px - x) + abs(py - y) for (x,y) in points])) == 1:
		res.append(px)
		res.append(py)
		break

print(" ".join(map(str,res)))