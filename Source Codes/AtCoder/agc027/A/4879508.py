n,x=[int(i) for i in input().split()]
a=sorted([int(i) for i in input().split()])

if sum(a)==x:
    print(n)
elif sum(a)<x:
    print(n-1)
else:
    ans=0
    for i in a:
        x-=i
        if x>=0:
            ans+=1
        else:
            break
    print(ans)