n,a,b=map(int, input().split())
h=[int(input()) for i in range(n)]
r,l=0,10**9
while r<l-1:
    c=(r+l+1)//2
    h2=[i-b*c for i in h if i-b*c>0]
    count=0
    for i in h2:
        count+=-(-i//(a-b))
    if count<=c:l=c
    else:r=c
print(l)