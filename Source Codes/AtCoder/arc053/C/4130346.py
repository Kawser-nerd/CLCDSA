iipt=lambda:int(input())
miipt=lambda:list(map(int, input().split()))

n=iipt()
up=[]
down=[]

for i in range(n):
    a,b=miipt()
    if a<b:
        down.append([a,b])
    else:
        up.append([b,a])
down.sort()
up.sort(reverse=True)
ans=0
t=0
for a,b in down:
    t+=a
    ans=max(ans, t)
    t-=b
for b,a in up:
    t+=a
    ans=max(ans, t)
    t-=b
print(ans)