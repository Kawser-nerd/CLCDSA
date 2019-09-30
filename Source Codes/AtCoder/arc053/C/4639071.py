import sys
input=sys.stdin.readline
n=int(input())
AB1,AB2=[],[]
for _ in range(n):
    a,b=map(int,input().split())
    if a<b:
        AB1.append((a,b))
    else:
        AB2.append((a,b))
AB1.sort()
AB2.sort(key=lambda x:x[1],reverse=True)
ans,temp=0,0
for a,b in AB1+AB2:
    temp+=a
    ans=max(ans,temp)
    temp-=b
print(ans)