N, Z, W = map(int, input().split())
a = list(map(int, input().split()))

if N == 1:
    print(abs(a[0] - W))
else:
    x = abs(a[-2] - a[-1])
    y = abs(a[-1] - W)
    
    ans = max(x, y)
    print(ans)