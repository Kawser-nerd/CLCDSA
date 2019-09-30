K = int(input())
N = int(input())

src = []
for i in range(N):
    a,d = map(int,input().split())
    src.append((a,d))

def ok(price):
    n = 0
    for a,d in src:
        n +=  max(0,  (price - a + d) // d)
        if n >= K: return True
    return False

l = 0
r = 10**20
while r-l > 0:
    m = (l+r)//2
    if ok(m):
        r = m
    else:
        l = m+1

ans = 0
k = 0
for a,d in src:
    n = max(0,  (l - a + d) // d)
    if n == 0: continue
    k += n
    ans += (2*a + d * (n-1)) * n // 2

ans -= (k-K)*l
print(ans)