N, K = map(int, input().split())
a = []
for _ in range(N):
    a.append(int(input())-K)
    
su = 0
v = [(0, 0)]
for i in range(N):
    su += a[i]
    v.append((su, i+1))
v = sorted(v)

data = [0]*(N+2)

def sumation(i):
    s = 0
    while i > 0:
        s += data[i]
        i -= i & -i
    return s
    
def add(i, x):
    while i <= N+1:
        data[i] += x
        i += i & -i
ans = 0
for e, i in v:
    ans += sumation(i+1)
    add(i+1, 1)
    
print(ans)