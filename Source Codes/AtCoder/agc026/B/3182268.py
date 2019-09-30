n = int(input())
def gcd(x,y):
	if x%y: return gcd(y,x%y)
	else: return y
for _ in range(n):
	a,b,c,d = (int(i) for i in input().split())
	g = gcd(b,d)
	if a<b or b>d or b-g+(a%g)>c: print("No")
	else: print("Yes")