def inin():
	return int(input())

def insp():
	return input().split()

s = []
d = []
r = []

def dfs(x, y):
	global s
	global d
	global r

	if d[x][y]:
		return r[x][y]

	d[x][y] = True
	if s[x][y] == '#':
		r[x][y] = True
		return r[x][y]

	if not dfs(x,y+1):
		r[x][y] = True
		return r[x][y]

	if not dfs(x+1,y):
		r[x][y] = True
		return r[x][y]

	if not dfs(x+1,y+1):
		r[x][y] = True
		return r[x][y]

	r[x][y] = False
	return r[x][y]

h,w = map(int,insp())

for i in range(h+2):
	d.append([])
	r.append([])
	for j in range(w+2):
		d[i].append(False)
		r[i].append(False)

s.append([])
for i in range(w+2):
	s[0].append('#')

for i in range(h):
	s.append(['#'] + list(input()) + ['#'])

s.append([])
for i in range(w+2):
	s[h+1].append('#')

if dfs(1,1):
	print("First")
else:
	print("Second")