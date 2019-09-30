n=int(input())
li=[0]*n
for i in range(n):
    li[i]=int(input())
fl=0
ans=0
if li[0]!=0:
    fl+=1
for i in range(n-1):
    if li[i]>=li[i+1]:
        ans+=li[i]
    if li[i+1]-li[i]>1:
        fl+=1
if fl>0:
    print(-1)
else:
    print(ans+li[n-1])