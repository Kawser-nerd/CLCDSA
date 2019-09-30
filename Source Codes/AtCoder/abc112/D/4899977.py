n,m=map(int,input().split())
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
            ans=pre_i1
            break
        pre_i1=i1
else:
    ans=pre_i1
print(ans)