from numpy import*
N,K=map(int,input().split())
m=zeros((3*K,3*K),dtype=int)
L=2*K
o=0
for _ in [0]*N:
 x,y,c=input().split()
 x,y=int(x)%L,int(y)%L
 t=c=='W'
 m[x,y]+=2*t-1
 o+=t
for _ in [0,0]:
 m[L:]=m[:K]
 m=cumsum(m,axis=0)
 m[:L]-=m[K:]
 m=m.T
m=m[:L,:L]
print(o-int((m+roll(roll(m,K,axis=0),K,axis=1)).min()))