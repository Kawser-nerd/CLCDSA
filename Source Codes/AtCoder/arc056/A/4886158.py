a,b,k,l=[int(i) for i in input().split()]
ans=b*(k//l)
k-=l*(k//l)
if a*k<=b:
    ans+=a*k
else:
    ans+=b
print(ans)