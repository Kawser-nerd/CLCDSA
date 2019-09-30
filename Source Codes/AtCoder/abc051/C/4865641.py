sx, sy, tx, ty = [
  int(i) for i in input().split()]

dx = tx - sx
dy = ty - sy

p1 = dy * 'U' + dx * 'R'
p2 = dy * 'D' + dx * 'L'
p3 = 'D' + (dx + 1) * 'R' + \
	(dy + 1) * 'U' + 'L'
p4 = 'U' + (dx + 1) * 'L' + \
	(dy + 1) * 'D' + 'R'
  
print(p1 + p2 + p3 + p4)