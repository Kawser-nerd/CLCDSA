a,b=map(int,input().split())
s=0
for i in range(b-a+1):
	s=s+i
print(s-b)