import sys
from math import fabs
inf = 10**10
N = int(input())
xyc = []
r = -inf
l = inf
u = -inf
d = inf
Mx = -inf
mx = inf
My = -inf
my = -inf

for i in range(N):
	x, y, c = map(int, input().split())
	xyc.append((x,y,c))
	r = max(r, x)
	l = min(l, x)
	u = max(u, y)
	d = min(d, y)

x_checked = 0
while r - l > 10**(-5):
	x_checked = 1
	m = (r+l)/2
	Mx = -10**10
	mx = 10**10
	for i in range(N):
		t = (xyc[i][0]-m)*xyc[i][2]
		Mx = max(Mx, t)
		mx = min(mx, t)

	if fabs(Mx) > fabs(mx):
		l = m
	else:
		r = m
y_checked = 0
while u - d > 10**(-5):
	y_checked = 1
	m = (u+d)/2
	My = -10**10
	my = 10**10
	for i in range(N):
		t = (xyc[i][1]-m)*xyc[i][2]
		My = max(My, t)
		my = min(my, t)

	if fabs(My) > fabs(my):
		d = m
	else:
		u = m
if x_checked and y_checked:
	print(max(fabs(Mx), fabs(mx), fabs(My), fabs(my)))
else:
	if x_checked and not y_checked:
		print(max(fabs(Mx), fabs(mx)))
	elif y_checked and not x_checked:
		print(max(fabs(My), fabs(my)))
	else:
		print(0)