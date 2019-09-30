M=int(input().split()[1]);e=1,0;C={};g=C.get;p=q=1;P=[]
for i in[0]*M:P+=list(map(float,input().split())),
Q={p:i for i,p in enumerate(sorted({p[0]for p in P}))};N=2**len(bin(len(Q)))
for x,a,b in P:
 x=Q[x];x+=N;C[x]=a,b
 while x:x>>=1;a,b=g(2*x,e);c,d=g(2*x+1,e);C[x]=a*c,c*b+d
 r=sum(C[1]);p=min(r,p);q=max(r,q)
print(p,q)