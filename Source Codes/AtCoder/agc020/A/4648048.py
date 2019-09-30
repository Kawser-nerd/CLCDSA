N, A, B = map(int, input().split())
d = abs(A - B) - 1
if d % 2 == 0:
    print("Borys")
else:
    print("Alice")