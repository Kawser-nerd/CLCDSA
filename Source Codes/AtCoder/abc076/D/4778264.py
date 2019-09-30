N=int(input().strip())
T=list(map(int,input().split()))
V=list(map(int,input().split()))
vtmax=[0]
tmp=0
Tsum=sum(T)
for t,v in zip(T,V):
    vtmax[-1]=min(tmp,v) #??????????
    vtmax+=[v]*(t*2)
    tmp=v
vtmax[-1]=0

for i in range(1,2*Tsum):
    vtmax[i]=min(vtmax[i],vtmax[i-1]+0.5)
for i in range(2*Tsum-1,0,-1):
    vtmax[i]=min(vtmax[i],vtmax[i+1]+0.5)
area=0
for i,vt in enumerate(vtmax):
    if i==0:continue
    area+=0.5*(vt+vtmax[i-1])/2
print(area)