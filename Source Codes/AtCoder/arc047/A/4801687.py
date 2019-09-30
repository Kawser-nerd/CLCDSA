n,l=[int(i) for i in input().split()]
s=input()
ans=0
cnt=1
for i in s:
    if i=="+":
        cnt+=1
    elif i=="-" and cnt>1:
        cnt-=1
    if cnt>l:
        ans+=1
        cnt=1
print(ans)