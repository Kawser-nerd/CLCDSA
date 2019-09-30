l,x,y,s,d = map(int,input().split())

ans1 = ((d-s)%l)/(y+x)
if y-x > 0:
  ans2 = ((l-d+s)%l)/(y-x)
else:
  ans2 = float("inf")

print(min(ans1,ans2))