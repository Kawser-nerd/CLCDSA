n=int(input())
pre=0
ans=0
for i in map(int,input().split()):
    if i < pre:
        ans+=pre-i
    pre=i
else:
    print(ans+i)