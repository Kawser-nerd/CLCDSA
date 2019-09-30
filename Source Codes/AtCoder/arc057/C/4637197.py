a=int(input())
l=a**2
r=(a+1)**2
ans=l
p=100
while p<r:
    u=((l-1)//p+1)*p
    if u<r:
        ans=u//p
    p*=100
print(ans)