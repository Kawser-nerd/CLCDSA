W, H, N = map(int, input().split())

x = 0
y = 0
a = 0
p1 = 0
p2 = W
p3 = 0
p4 = H
for i in range(N):
	x, y, a = map(int, input().split())

	if a==1:
		p1 = max(p1, x)
	elif a==2:
		p2 = min(p2, x)
	elif a==3:
		p3 = max(p3, y)
	elif a==4:
		p4 = min(p4, y)

if p1>=p2 or p3>=p4:
	print(0)
else:
	print((p2-p1)*(p4-p3))