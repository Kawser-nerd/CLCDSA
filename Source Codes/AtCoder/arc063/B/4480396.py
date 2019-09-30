n,_,*a=map(int,open(0).read().split())
m=d=c=0
for t in a[::-1]:
    if t>m:
        m=t
    if m-t>d:
        d=m-t
        c=1
    elif m-t==d:
        c+=1
print(c)