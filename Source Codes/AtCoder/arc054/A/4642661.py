l,x,y,s,d = map(int,input().split())
if s <= d:
    k = d - s
else:
    k = d - s + l
if x < y:
    ans = min(
        k/(y+x),(l-k)/(y-x)
    )
else:
    ans = k/(x+y)
print(ans)