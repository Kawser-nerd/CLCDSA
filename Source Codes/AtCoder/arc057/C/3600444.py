r=int(input())
s=r*r
t=(r+1)**2
a=s
p=100
while p<t:
    u=((s-1)//p+1)*p
    if u<t:
        a=u//p
    p*=100    
print(a)