#!/usr/bin/python
# python 2.6.1
# input from stdin, output to stdout

def read_int():
	return int(raw_input().strip())

def read_ints():
	return [int(x) for x in raw_input().strip().split()]

def choose(n,k):
	b=[0]*(n+1)
	b[0]=1
	for i in range(n):
		b[i+1] = 1
		for j in range(i,0,-1):
			b[j] += b[j - 1]
	return b[k]

# have k things out of c total
# choose n more
# Pr[x things are new]= choose(n,x)*(c-k / c)*(c-k-1 / c)*...*(c-k-x / c)*(k/c)*(k-1/c)*...*(k-(n-x))
def prob(c,n,k,x):
	p=1.0
	p=p*choose(n,x)
	for i in range(x):
		p=p*(c-k-i)/(c-i)
	for i in range(n-x):
		p=p*(k-i)/(c-x-i)
	return p
	
def main():
	t=read_int()
	for I in range(t):
		[c,n]=read_ints()
		# p[i] = probability of having i out of c cards given q[] probabilites previously
		p=[1.0]+[0.0]*c
		q=[0.0]*(c+1)
		R=0
		E=0.0
		while sum(abs(a-b) for (a,b) in zip(p,q))>1e-8:
			q=p
			p=[0.0]*(c+1)
#			print q
			for i in range(c+1):
				for j in range(i,min(c,i+n)+1):
					z=prob(c,n,i,j-i)
#					print repr((i,j,z))
					# have i things out of c, choose n, probability of getting j-i new things
					p[j]+=q[i]*z
			R+=1
			E+=R*(p[c]-q[c])
#			print E
		print "Case #%d: %f" % (I+1,E)
	
if __name__=="__main__":
	main()
	
