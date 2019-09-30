a,b=map(int,input().split())
s=1
c=0
for i in input():
    s+=(i=="+")
    s-=(i=="-")
    if s==b+1:
        c+=1
        s=1
print(c)