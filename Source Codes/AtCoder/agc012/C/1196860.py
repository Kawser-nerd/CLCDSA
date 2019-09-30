def nCr(a,b):
	tmp=1
	for i in range(a,a-b,-1):tmp*=i
	for i in range(1,b+1,1):tmp//=i
	return tmp

n=int(input())
out=[]
co=1
coo=0
while n>0:
	t=2
	while True:
		sum1=0
		for j in range(2,t+1,2):
			sum1+=nCr(t,j)
#		print(n,sum)
		if n<sum1:
			t-=1
#			n-=rco
			break
		rco=sum1
		t+=1
	ad=[co for _ in range(t)]
	sum1=rco
	ma=sum1
#	print(ma)
	for toa in range(1,4):
		for tob in range(1,4):
			CO=0
			for r in range(1,min(toa,tob)+1):
				CO+=nCr(toa,r)*nCr(tob,r)
		
			for a in range(1,t):
				sum2=sum1+((2**(toa+tob-1))-1)
				for b in range(1,a+1):
					sum2+=nCr(a,b)*nCr(t-a,b)*CO
				if sum2>n:continue
				if ma<sum2:
					ma=sum2
					ad=[co for _ in range(a)]
					for _ in range(toa):ad.append(100-coo)
					for _ in range(t-a):ad.append(co)
					for _ in range(tob):ad.append(100-coo)
	
#	print(ad,0,ma)
	for t in ad:out.append(t)
#	out.append(ad)
	n-=ma
	coo+=1
	co+=1
print(len(out))
print(*out)