import bisect
class BITree:
    def __init__(self, n):
        self.size = n
        self.tree = [0] * (n + 1)
 
    def query(self, i):
        s = 0
        while i > 0:
            s = max(self.tree[i],s)
            i -= i & -i
        return s
 
    def update(self, i, x):
        while i <= self.size:
            self.tree[i] = max(self.tree[i],x)
            i += i & -i

N=int(input())
X=[]
for i in range(N):
    h,w=map(int,input().split())
    X.append((h,-w))
X.sort()
h0=[i[0] for i in X]
w0=[-i[1] for i in X]
h1=sorted(list(set(h0)))
w1=sorted(list(set(w0)))
h=[bisect.bisect_left(h1,t)+1 for t in h0]
w=[bisect.bisect_left(w1,t)+1 for t in w0]
dp=[0 for i in range(N)]
bit=BITree(N)
for i in range(N):
    dp[i]=bit.query(w[i]-1)+1
    bit.update(w[i],dp[i])
print(max(dp))