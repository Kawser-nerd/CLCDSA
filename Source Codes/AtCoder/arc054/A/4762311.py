l,x,y,s,d=[int(i) for i in input().split()]

if s<=d:
    ans=(d-s)/(x+y)
else:
    ans=(d-s+l)/(x+y)
if x<y:
    if s>=d:
        ans=min(ans,(s-d)/(y-x))
    else:
        ans=min(ans,(l-d+s)/(y-x))
print(ans)