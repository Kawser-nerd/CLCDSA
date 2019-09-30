r,b=map(int,input().split())
x,y=map(int,input().split())
left=0
right=min(r,b)+1
while right-left>1:
    m=(right+left)//2
    cnt=(r-m)//(x-1)+(b-m)//(y-1)
    if cnt<m:
        right=m
    else:
        left=m
print(left)