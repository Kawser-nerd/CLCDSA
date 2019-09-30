k=int(input())
n=1
t=1
l=0
for i in range(k):
	print(n)
	if int(n/t)%10==9:
		if n+t<=(9*l+int((n+t)/(t*10))%10+int((n+t)/(t*100))%100+int((n+t)/(t*1000))%1000)*t:
			pass
		else:
			t *= 10
			l += 1
	n += t