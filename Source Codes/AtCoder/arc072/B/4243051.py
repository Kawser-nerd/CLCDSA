x, y = map(int, input().split())
m = min(x, y)
x -= m
y -= m
if x == y:
    print("Brown")
else:
    if max(x, y) == 1:
        print("Brown")
    else:
        print("Alice")