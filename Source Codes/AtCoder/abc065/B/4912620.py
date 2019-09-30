N = int(input())
a = [int(input()) for i in range(N)]

if 2 in a:
	l = 1
	count = 0
	while 1:
		if l==2:
			print(count)
			break
		elif a[l-1]==0:
			print(-1)
			break
		temp = l-1
		l = a[l-1]
		a[temp] = 0 
		count += 1
else:
	print(-1)