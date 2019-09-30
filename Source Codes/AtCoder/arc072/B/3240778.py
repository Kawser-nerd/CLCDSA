x, y = map(int, input().split())
print("Brown" if abs(x-y) < 2 else "Alice")