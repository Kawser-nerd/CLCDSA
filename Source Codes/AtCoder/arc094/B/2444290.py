import math
q=int(input())
for j in range(q):
	AB=[int(i) for i in input().split()]
	AB.sort()#4,11
	ab=AB[0]*AB[1] #44
	for i in range(int(math.sqrt(ab)),AB[1]+1):
		if i*i>=ab:
			x=i-1
			break
	if x==0:
		print(0)
		continue
	for i in range(int(ab/x),ab+1):
		if x*i>=ab:
			y=i-1
			break
	cnt1=2*x
	cnts=1 if x==y else 0
	cntdd=1 if x-AB[0]>=0 else 0
	cntdu=1 if AB[1]-y>=0 and (AB[1]+1)*(x-AB[1]+y)>=ab else 0 #x-i, y+i=c,b->c,b+1
	print(cnt1-cnts-cntdd-cntdu)