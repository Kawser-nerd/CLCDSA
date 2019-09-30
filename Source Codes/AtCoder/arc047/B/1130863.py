n = int(input())
x = [0]*n
y = [0]*n
tx = [0]*n
ty = [0]*n
mx = [0]*2
my = [0]*2
for i in range(n):
	x[i], y[i] = map(int, input().split())
	tx[i] = x[i]+y[i]
	ty[i] = x[i]-y[i]
 
mx[0] = min(tx)
mx[1] = max(tx)
my[0] = min(ty)
my[1] = max(ty)
D = max(mx[1]-mx[0], my[1]-my[0])/2
 
for i in range(2):
	for j in [-1, 1]:
		tax = mx[i]+D*j
		tay = my[i]+D*j
		ax = int((tax+tay)/2)
		ay = int((tax-tay)/2)
		d = abs(ax-x[0])+abs(ay-y[0])
		flag = True
		for k in range(1,n):
			if d != abs(ax-x[k])+abs(ay-y[k]):
				flag = False
				break
		if flag:
			print(ax, ay)
			exit()