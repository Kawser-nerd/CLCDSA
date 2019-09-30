from scipy.sparse.csgraph import floyd_warshall as fw
N,M=map(int,input().split())
g=[[0for j in range(N)]for i in range(N)]
for i in range(M):
    a,b,t=map(int,input().split())
    g[a-1][b-1]=g[b-1][a-1]=t
print(min([int(max(l))for l in fw(g)]))