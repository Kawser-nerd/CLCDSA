n,h = map(int,input().split())
AB = [list(map(int,input().split())) for i in range(n)]
AB.sort(reverse=True)
weapon = []
x = AB[0][0]
for a,b in AB:
	if b >= x:
		weapon.append(b)
weapon.sort(reverse=True)
weapon.append(x)
cnt = 0
for w in weapon[:-1]:
	h -= w
	cnt += 1
	if h <= 0:
		print(cnt)
		exit()
from math import ceil
cnt += ceil(h/weapon[-1])
print(cnt)