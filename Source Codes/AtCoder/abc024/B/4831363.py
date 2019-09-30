n,t=map(int,input().split(' '))
a=[]
x=0
y=0
for i in range(n):
    a.append(int(input()))
for i in range(1,n):
    if abs(a[i]-a[i-1])>t:
        x+=t
    elif abs(a[i]-a[i-1])-y<=t:
        x+=abs(a[i]-a[i-1])
        y=t
print(x+t)