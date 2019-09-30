n,k=map(int, input().split())
a=[int(input()) for i in range(n)]
b=[]
c=-1
d=0
for i in range(n):
    if a[i]>c:
        d+=1
        c=a[i]
    else:
        b.append(d)
        d=1
        c=a[i]
b.append(d)
ans=0
for i in b:
    ans+=max(i-k+1,0)
print(ans)