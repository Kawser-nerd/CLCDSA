from collections import defaultdict

s = list(input())
x, y = list(map(int, input().split()))

X = []
Y = []
judge = "x"
l = 0
for i in s:
	if i == "F":
		l += 1
	else:
		if judge == "x":
			if l != 0:
				X.append(l)
			judge = "y"
		else:
			if l != 0:
				Y.append(l)
			judge = "x"
		l = 0

if judge == "x":
	if l != 0:
		X.append(l)
else:
	if l != 0:
		Y.append(l)

jj = "bad"
if len(s) >= 2:
	if s[0] == "T":
		jj = "good"


dx = defaultdict(int)
if X != []:
	if jj == "good":
		dx[X[0]] = 1
		dx[-X[0]] = 1
	else:
		dx[X[0]] = 1
	X.remove(X[0])
else:
	dx[0] = 1

for i in range(len(X)):
	D = defaultdict(int)
	for j in dx:
		if dx[j] == 1:
			D[j + X[i]] = 1
			D[j - X[i]] = 1
	dx = D


dy = defaultdict(int)
if Y != []:
	dy[Y[0]] = 1
	dy[-Y[0]] = 1
	Y.remove(Y[0])
else:
	dy[0] = 1

for i in range(len(Y)):
	D = defaultdict(int)
	for j in dy:
		if dy[j] == 1:
			D[j + Y[i]] = 1
			D[j - Y[i]] = 1
	dy = D

if dx[x] == 1 and dy[y] == 1:
	print("Yes")
else:
	print("No")