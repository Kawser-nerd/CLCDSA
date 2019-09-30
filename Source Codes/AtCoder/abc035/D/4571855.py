from scipy.sparse import*
n,m,t,*a=map(int,open(0).read().split());x=(a[n::3],a[n+1::3])
print(int(max(a*(t-g-h)for a,g,h in zip(a,*[csgraph.dijkstra(csr_matrix((a[n+2::3],k),[n+1]*2),1,1)[1:]for k in[x,x[::-1]]]))))