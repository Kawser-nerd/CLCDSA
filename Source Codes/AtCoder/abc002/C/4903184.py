x,y,at,bt,ct,dt=map(int,input().split())
a=at-x
b=bt-y
c=ct-x
d=dt-y
m=abs((a*d)-(b*c))
print(m/2)