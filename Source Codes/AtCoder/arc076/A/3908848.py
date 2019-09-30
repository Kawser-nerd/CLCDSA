n, m = map(int, input().split())
a = 1
b = 1
if abs(n-m) >= 2:
    print(0)
else:
    for i in range(2, n+1):
        a = (a*i) % (10**9+7)
    for j in range(2, m+1):
        b = (b*j) % (10**9+7)
    if n == m:
        print((a*b*2) % (10**9+7))
    else:
        print((a*b) % (10**9+7))