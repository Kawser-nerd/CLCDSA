n=int(input())
L=[]
L.append(int(input()))
ans=1
for i in range(n-1):
    L.sort()
    a=int(input())
    y=0
    for j in range(len(L)):
        if L[j]>=a:
            L[j]=a
            y=1
            break
    if y==0:
        ans+=1
        L.append(a)
print(ans)