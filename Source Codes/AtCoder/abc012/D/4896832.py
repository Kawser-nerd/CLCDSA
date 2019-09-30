from scipy.sparse.csgraph import floyd_warshall as fw
n,m=map(int,input().split())
s=[[(0 if i==j else float("inf"))for i in range(n)]for j in range(n)]
for i in range(m):
    a,b,t=map(int,input().split())
    s[a-1][b-1]=t
    s[b-1][a-1]=t
print(int(min([max(i) for i in fw(s)])))