h,m=map(int,input().split())
ans=0
if m>0:
    ans+=60-m
    ans+=60*(18-1-h)
else:
    ans+=60*(18-h)
print(ans)