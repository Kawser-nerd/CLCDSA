n=int(input())
a=list(map(int,input().split()))
p=[1,-1]
j=[-1,1]
c=0
l=0
d=0
e=0
for i in range(n):
    s=i%2
    c+=a[i]
    l+=a[i]
    if p[s]*c<=0:
        d+=abs(c-p[s])
        c=p[s]
    if j[s]*l<=0:
        e+=abs(l-j[s])
        l=j[s] 
print(min(e,d))