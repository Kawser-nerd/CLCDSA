P=[list(map(float,input().split()))for i in[0]*int(input().split()[1])];Q={p:i for i,p in enumerate(sorted({p[0]for p in P}))};N=2**len(bin(len(Q)));C=[(1,0)]*(N*2);V=[1]
for x,a,b in P:
 x=Q[x]+N;C[x]=a,b
 while x:x>>=1;a,b=C[2*x];c,d=C[2*x+1];C[x]=a*c,c*b+d
 V+=c+d,
print(min(V),max(V))