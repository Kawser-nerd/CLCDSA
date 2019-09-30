a, b = map(int, input().split())
if b % a:
    print(b - a)
else:
    print(a + b)