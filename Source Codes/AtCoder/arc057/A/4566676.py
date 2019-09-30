a,k=map(int,input().split())
c=int(2*1e12)
if k==0:
    print(c-a)
else:
    p=0
    while a<c:
        a+=1+a*k
        p+=1
    print(p)