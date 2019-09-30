a, b, c = [int(n) for n in input().split()]
if a == b:
    print(c)
else:
    if a == c:
        print(b)
    else:
        print(a)