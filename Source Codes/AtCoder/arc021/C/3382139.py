k = int(input())
n = int(input())
x = [tuple([int(i) for i in input().split()]) for i in range(n)]
ans,k2,x = 0,0,sorted(x)
def f(p):
	a = 0
	for i,j in x:
		if p>=i: a+=(p-i+j)//j
		else: break
	return a<k
hi,lo = 10**20,0
while hi!=lo+1:
	m = (hi+lo)//2
	if f(m): lo = m
	else: hi = m
for i,j in x:
	if hi>=i:
		num = (hi-i+j)//j
		k2+=num
		ans+=i*num+(num-1)*num*j//2
	else: break
print(ans-(k2-k)*hi)