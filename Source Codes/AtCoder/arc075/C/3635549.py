def inpl(): return [int(i) for i in input().split()]
class BIT:
    def __init__(self, n):
        self.size = n
        self.tree = [0] * (n + 1)
 
    def suma(self, i):
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & -i
        return s
 
    def add(self, i, x):
        while i <= self.size:
            self.tree[i] += x
            i += i & -i

N, K = inpl()
a = [0]
for _ in range(N):
    a.append(a[-1] + int(input()) -K)
c = dict([])
for i, v in enumerate(sorted(set(a))):
    c[v] = i+1
Tr = BIT(N+1)
ans = 0
for v in a:
    ans += Tr.suma(c[v])
    Tr.add(c[v], 1)
print(ans)