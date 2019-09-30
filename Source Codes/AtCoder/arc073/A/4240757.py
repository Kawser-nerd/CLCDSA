n,t=map(int,input().split())
p=list(map(int,input().split()))
a=0
for i in range(1,n):
    if p[i-1]+t<p[i]:
        a+=t
        s=p[i] 
    else:
        a+=p[i]-p[i-1]
print(a+t)