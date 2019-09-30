h,w=map(int,input().split())
def solve(a,b):
    if a%2==0 or b%2==0:
        return a*b//2,a*b//2
    return min(a,b)*(max(a,b)//2),min(a,b)*(1+max(a,b)//2)
ret=h*w
for x in range(1,w):
    mi,ma = solve(h,w-x)
    ret=min(ret,max([ma-mi,ma-h*x,h*x-mi]))
for x in range(1,h):
    mi,ma = solve(w,h-x)
    ret=min(ret,max([ma-mi,ma-w*x,w*x-mi]))
print(ret)