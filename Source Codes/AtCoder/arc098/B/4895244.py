n=int(input())
a=list(map(int,input().split()))
d=0
e=0
f=0
for i in range(n):
    while e<n and d&a[e]==0:
        d+=a[e]
        e+=1
    d-=a[i]
    f+=e-i
print(f)