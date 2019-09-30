n, m = list(map(int, input().split()))
n, m = max(n, m), min(n, m)
if n == 1 and m == 1:
    print(1)
else:
    a = min(2, n)
    b = max(0, n-2)
    c = min(2, m)
    d = max(0, m-2)
    if m == 1:
        print(b)
    else:
        print(b*d)