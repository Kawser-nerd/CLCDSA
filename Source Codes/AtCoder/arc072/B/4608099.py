X, Y = list(map(int, input().split()))
if X == Y or abs(X - Y) == 1:
    print("Brown")
else:
    print("Alice")