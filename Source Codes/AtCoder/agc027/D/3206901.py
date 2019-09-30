z=int(input())
n=500

def gcd(a,b):
	while b:
		a,b=b,a%b
	return a

def lcm(a,b):
	return a*b//gcd(a,b)

def lcm3(a,b,c):
	return lcm(lcm(a,b),c)

def lcm4(a,b,c,d):
	return lcm(lcm(a,b),lcm(c,d))

a=[0]*(n*n)
x=set([1])
for i in range(n*n//4)[::-1]:
	j=i//((n*n)//16)
	if j==0:
		y1=0
		y2=0
	elif j==1:
		y1=1
		y2=1
	elif j==2:
		y1=0
		y2=1
	else:
		y1=1
		y2=0
	k=i%((n*n)//16)
	m=i+2
	a[n*(4*(k//(n//4))+2*y1)+4*(k%(n//4))+2*y2]=m
	x.add(m)
	while m in x:
		m+=i+2
	a[n*(4*(k//(n//4))+2*y1+1)+4*(k%(n//4))+2*y2+1]=m
	x.add(m)
#print(a)
for i in range(0,n*n):
	if a[i]==0:
		j=i//n
		k=i%n
		if j==0 and k==n-1:
			m=lcm(a[i-1],a[i+n])
			l=m+1
			while l in x:
				l+=m
			a[i]=l
			x.add(l)
		elif j==n-1 and k==0:
			m=lcm(a[i+1],a[i-n])
			l=m+1
			while l in x:
				l+=m
			a[i]=l
			x.add(l)
		elif j==0:
			m=lcm3(a[i-1],a[i+1],a[i+n])
			l=m+1
			while l in x:
				l+=m
			a[i]=l
			x.add(l)
		elif j==n-1:
			m=lcm3(a[i-1],a[i+1],a[i-n])
			l=m+1
			while l in x:
				l+=m
			a[i]=l
			x.add(l)
		elif k==0:
			m=lcm3(a[i+1],a[i-n],a[i+n])
			l=m+1
			while l in x:
				l+=m
			a[i]=l
			x.add(l)
		elif k==n-1:
			m=lcm3(a[i-1],a[i-n],a[i+n])
			l=m+1
			while l in x:
				l+=m
			a[i]=l
			x.add(l)
		else:
			m=lcm4(a[i+1],a[i-1],a[i-n],a[i+n])
			l=m+1
			while l in x:
				l+=m
			a[i]=l
			x.add(l)

#print(max(x))

for i in range(z):
	print(' '.join(map(str,a[i*n:i*n+z])))