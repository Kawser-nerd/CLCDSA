N, A, B = map(int, input().split())
su = 0
ma = -1
mi = 10**10
for _ in range(N):
    s = int(input())
    su += s
    ma = max(ma, s)
    mi = min(mi, s)
    
ave = su/N
if ma == mi:
    print(-1)
else:
    a = B / (ma-mi)
    b = A - ave * a
    print(a, b)