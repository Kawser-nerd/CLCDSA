a, b, c = [int(item) for item in input().split()]
if a == b:
    print(c)
elif b == c:
    print(a)
elif a == c:
    print(b)
else:
    print("wrong")