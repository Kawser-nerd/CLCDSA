import collections 
n,k=map(int,input().split())
c=list(map(int,input().split()))
l=collections.Counter(c)
s=l.most_common()
p=[]
if len(s)<=k:
    print(0)
else:
    d=0
    for a,b in s[:k]:
        d+=b
    print(n-d)