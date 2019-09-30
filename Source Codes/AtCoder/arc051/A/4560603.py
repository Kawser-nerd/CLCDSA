x,y,r=map(int,input().split())
s,t,h,w=map(int,input().split())
if s<=x-r and x+r<=h and t<=y-r and y+r<=w:
    print("NO")
else:
    print("YES")
if (max(abs(x-s),abs(x-h))**2+max(abs(y-t),abs(y-w))**2)**0.5<=r:
    print("NO")
else:
    print("YES")