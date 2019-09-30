n=int(input())
ans=[0]*1000001
for i in range(n):
    a,b=[int(i) for i in input().split()]
    ans[a]+=1
    try:
        ans[b+1]-=1
    except:
        pass
for i in range(1,1000001):
    ans[i]+=ans[i-1]
print(max(ans))