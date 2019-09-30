n,k=map(int,input().split())
a=[list(map(int,input().split()))for i in range(n)]
d=100
e=0
while d-e>10**-8:
    h=(d+e)/2
    c=sorted([w*(p-h)*10**(-2) for w,p in a])[::-1]
    if sum(c[:k])>=0:
        e=h
    else:
        d=h
print(e)