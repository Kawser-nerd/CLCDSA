class BITree:
    def __init__(self, n):
        self.size = n
        self.tree = [0] * (n + 1)
 
    def sum(self, i):
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & -i
        return s
 
    def add(self, i, x):
        while i <= self.size:
            self.tree[i] += x
            i += i & -i
N,K=map(int,input().split())
a=[int(input()) for i in range(N)]
b=[0 for i in range(N+1)]
for i in range(N):
    b[i+1]=b[i]+a[i]-K
btmp=sorted([(b[i],i) for i in range(N+1)])
c=[-1 for i in range(N+1)]
for i in range(N+1):
    c[btmp[i][1]]=i+1
bit=BITree(N+1)
ans=0
for j in range(N+1):
    ans+=j-bit.sum(c[j])
    bit.add(c[j],1)
print((N*(N+1))//2-ans)