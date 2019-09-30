N,L=map(int,input().split())
S=input()
tab=1
ans=0
for i in S:
    if i=="+":
        tab+=1
    else:
        tab-=1
    if tab>L:
        ans+=1
        tab=1
print(ans)