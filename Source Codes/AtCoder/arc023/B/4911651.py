r,c,d=map(int,input().split())
k=0
for i in range(r):
    a=list(map(int,input().split()))
    for j in range(c):
        g=i+j
        if g<=d and (d-g)%2==0:
            k=max(a[j],k)
print(k)