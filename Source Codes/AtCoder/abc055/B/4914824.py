N=int(input())
p=1
for i in range(2,N+1):
	p=(p*i)%1000000007
print(p)