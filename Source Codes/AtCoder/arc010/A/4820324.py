n,m,a,b = map(int,input().split())
cnt = 0
for i in range(m):
	if n <= a:
		n += b
	cnt += 1
	c = int(input())
	n -= c
	if n < 0:
		print(cnt)
		exit()
print("complete")