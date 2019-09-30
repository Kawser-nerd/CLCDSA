n,q=map(int,input().split())
l=[0 for i in range(n+1)]
for i in range(q):
    a=[int(j) for j in input().split()]
    l[a[0]-1]+=1
    l[a[1]]-=1

li=[0]
def ruiseki(a):
    for i in range(len(a)):
        li.append(li[i]+a[i])
    del li[0]
ruiseki(l)
ans=""
for i in range(n):
    ans+=str(li[i]%2)
print(ans)