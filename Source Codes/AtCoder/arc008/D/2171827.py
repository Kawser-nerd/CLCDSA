V=[1];P=[list(map(float,input().split()))for i in V*int(input().split()[1])];Q={p:i for i,p in enumerate(sorted({p[0]for p in P}))};N=2**20;C=[(1,0)]*N
for x,a,b in P:
 x=Q[x]+N//2;C[x]=a,b
 while x:x>>=1;a,b=C[2*x];c,d=C[2*x+1];C[x]=a*c,c*b+d
 V+=c+d,
print(min(V),max(V))