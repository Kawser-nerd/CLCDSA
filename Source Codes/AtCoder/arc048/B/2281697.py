n = int(input())
r,h = [0 for i in range(n)],[0 for i in range(n)]
t = [[0 for i in range(111111)] for j in range(3)]
for i in range(n):
	r[i],h[i] = map(int,input().split())
	h[i] -= 1
	t[h[i]][r[i]] += 1
for i in range(100000):
	for j in range(3):
		t[j][i+1] += t[j][i]
for i in range(n):
	w,l = (h[i]+1)%3,(h[i]+2)%3
	x = t[0][r[i]-1] + t[1][r[i]-1] + t[2][r[i]-1]
	y = n - (t[0][r[i]] + t[1][r[i]] + t[2][r[i]])
	x += t[w][r[i]] - t[w][r[i]-1]
	y += t[l][r[i]] - t[l][r[i]-1]
	print("{} {} {}".format(x,y,n-x-y-1))