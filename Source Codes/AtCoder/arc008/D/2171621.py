M=int(input().split()[1]);p=q=1;P=[list(map(float,input().split()))for i in[0]*M];Q={p:i for i,p in enumerate(sorted({p[0]for p in P}))};N=2**len(bin(len(Q)));C=[(1,0)]*(N*2)
for x,a,b in P:
 x=Q[x]+N;C[x]=a,b
 while x:x>>=1;a,b=C[2*x];c,d=C[2*x+1];C[x]=a*c,c*b+d
 r=sum(C[1]);p=min(r,p);q=max(r,q)
print(p,q)