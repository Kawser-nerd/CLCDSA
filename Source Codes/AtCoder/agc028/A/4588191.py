n,m=map(int,input().split())
s=input()
t=input()

#?????
def gcd(x,y):
    if y==0:
        return x
    else:
        return gcd(y,x%y)

#?????
def lcm(x,y):
    return x*y//gcd(x,y)

l=lcm(n,m)

a=l//n
b=l//m
ln=[]
lm=[]
i=0
while i<n:
    ln.append(i)
    i+=b
i=0
while i<m:
    lm.append(i)
    i+=a

p=0
for i in range(len(ln)):
    if s[ln[i]]!=t[lm[i]]:
        p=1
if p==0:
    print(l)
else:
    print(-1)