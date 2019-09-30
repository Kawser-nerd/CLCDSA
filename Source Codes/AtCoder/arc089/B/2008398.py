import numpy as np
N,K=map(int,input().split())
m=np.zeros((3*K,3*K),dtype=int)
L=2*K
o=0
for _ in [0]*N:
	x,y,c=input().split()
	x,y=int(x)%L,int(y)%L
	t=c=='W'
	m[x,y]+=1-2*t
	o+=t
for _ in [0,0]:
	m[L:]=m[:K]
	m=np.cumsum(m,axis=0)
	m[:L]=m[K:]-m[:L]
	m=m.T
m=m[:L,:L]
print(o+(m+np.roll(np.roll(m,K,axis=0),K,axis=1)).max())