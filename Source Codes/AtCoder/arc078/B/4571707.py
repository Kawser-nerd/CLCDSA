from scipy.sparse import*
n,*a=map(int,open(0).read().split())
print('FSennunkeec'[sum(g>h for g,h in zip(*csgraph.dijkstra(csr_matrix(([1]*~-n,(a[::2],a[1::2])),[n+1]*2),0,[1,n])))*2>=n::2])