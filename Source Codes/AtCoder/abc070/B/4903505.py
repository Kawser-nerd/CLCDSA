a,b,c,d=map(int,input().split())
ans=0
if min(b,d)-max(a,c)>=0:
    ans=min(b,d)-max(a,c)
print(ans)