I=lambda:map(int,input().split())
n,m=I()
v=[0]*n
d=[1]+[0]*2**n
for _ in[0]*m:s,g=I();v[s-1]+=1<<g-1
i,j=0,-1
for _ in range(n*2**n):
    j+=1
    if j==n:
        i+=1
        j=0
    d[i|1<<j]+=d[i]*(i&(1<<j|v[j])<1)
print(d[-2])