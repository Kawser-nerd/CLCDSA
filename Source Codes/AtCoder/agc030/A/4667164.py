a, b, c = map(int, input().split())
if a+b >= c:
    print(b+c)
else:
    ans = a+b + 1 + b
    print(ans)