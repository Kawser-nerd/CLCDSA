a,b,c=map(int,input().split())
def gcd(a, b):
	while b:
		a, b = b, a % b
	return a
if c==0:
    print("YES")
elif c%gcd(a,b)==0 and c!=0:
    print("YES")
else:
    print("NO")