n,m=map(int, input().split())
a=[int(input()) for i in range(n)]
w=10**9+7
a2=[]
left=0
m=dict()
for right in range(n):
    m[a[right]]=m.get(a[right],0)+1
    while left<right and m.get(a[right],0)>1:
        m[a[left]]=m.get(a[left],1)-1
        left+=1
    a2.append(left)

dp=[1]
sumdp=[0,1]
for i in range(n):
    dp.append(sumdp[-1]-sumdp[a2[i]])
    sumdp.append((sumdp[-1]+dp[-1])%w)
print(dp[-1]%w)