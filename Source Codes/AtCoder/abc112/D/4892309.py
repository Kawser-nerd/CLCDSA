n,m = map(int,input().split())
factor = [1,m]
for i in range(2,int(m**0.5)+2):
	if m%i == 0:
		factor.append(i)
		factor.append(m//i)	
factor.sort(reverse=True)
for f in factor:
	if f <= m//n:
		print(f)
		exit()