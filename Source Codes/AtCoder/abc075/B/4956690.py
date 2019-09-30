h,w = map(int, input().split())
s = [list(input()) for i in range(h)]
dx = [-1,0,1]
dy = [-1,0,1]
for i in range(h):
	for j in range(w):
		count = 0
		if s[i][j] == '#':
			continue
		if s[i][j] == '.':
			for l in dx:
				for m in dy:
					if i+l< 0 or i+l > h-1 or j+m < 0 or j+m > w-1:
						continue
					if s[i+l][j+m] == '#':
						count += 1
		s[i][j] = str(count)
for i in s:
	k = ''.join(i)
	print(k)