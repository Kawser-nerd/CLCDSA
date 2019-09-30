r,b=map(int,input().split())
x,y=map(int,input().split())
l=10**18+1
k=0
while l-k>1:
    s=(l+k)//2
    if r-s>=0 and b-s>=0:
        if ((r-s)//(x-1))+((b-s)//(y-1))>=s:
            k=s
        else:
            l=s
    else:
        l=s
print(k)