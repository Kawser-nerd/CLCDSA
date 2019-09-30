n,k=map(int,input().split())
d=[]
for i in range(1,31700):
    if i*i>k:
        break
    else:
        if k%i==0:
            d.append([i,(n//i)*(n//i+1)//2*i])
            if k!=i*i:
                p=k//i
                d.append([p,(n//p)*(n//p+1)//2*p])
d.sort()
for i in range(len(d)-1,-1,-1):
    for j in range(i):
        if d[i][0]%d[j][0]==0:
            d[j][1]-=d[i][1]
a=0
for i,t in d:
    a+=t*(k//i)
print(a%(10**9+7))