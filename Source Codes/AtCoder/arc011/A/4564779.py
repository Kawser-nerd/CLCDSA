m,n,d=map(int,input().split())
c=d
while d>=m:
    c+=d//m*n
    d=n*(d//m)+d%m
print(c)