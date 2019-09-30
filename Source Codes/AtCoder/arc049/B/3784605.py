iipt=lambda:int(input())
miipt=lambda:list(map(int,input().split(" ")))

n=iipt()
x=[0]*1123
y=[0]*1123
c=[0]*1123
for i in range(n):
    x[i],y[i],c[i]=miipt()
tx=ty=0
for i in range(n):
    for j in range(i+1,n):
        tx=max(tx, abs(x[i]-x[j])/(1/c[i]+1/c[j]))
        ty=max(ty, abs(y[i]-y[j])/(1/c[i]+1/c[j]))
print(max(tx,ty))