n,m=map(int,input().split())
f1=[]
f2=[]
for i1 in range(1,int(m**0.5)+1):
    if m%i1==0:
        i2=m//i1
        if i1>=n:
            ans=i2
            break
        elif i2==n:
            ans=i1
            break
        elif i2<n:
            ans=f1[-1]
            break
        f1+=[i1]
        f2+=[i2]
else:
    ans=f1[-1]
print(ans)