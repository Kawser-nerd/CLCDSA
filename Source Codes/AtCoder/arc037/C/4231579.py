from bisect import bisect_right
n,k=map(int,input().split())
a=sorted(map(int,input().split()))
b=list(map(int,input().split()))
l,r=0,10**18+1
while r-l>1:
    x=(r+l)//2
    count=sum(bisect_right(a,x//bi) for bi in b)
    if count<k:
        l=x
    else:
        r=x
print(r)