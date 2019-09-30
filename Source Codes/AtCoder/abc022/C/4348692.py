import numpy as np,scipy.sparse.csgraph as ssc
inf=1e9
N,M=map(int,input().split())
D=np.array([[inf]*N]*N)
for i in range(M):
    u,v,l=map(int,input().split())
    D[u-1,v-1]=D[v-1,u-1]=l
K=np.array(D)
K[:][0]=K[0][:]=[inf]*N;
K=ssc.floyd_warshall(K)
res=min(min(D[0,i]+D[0,j]+K[i,j] for j in range(i+1,N)) for i in range(1,N-1))
print(int([-1,res][res<inf]))