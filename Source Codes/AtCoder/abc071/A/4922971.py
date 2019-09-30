x, a, b = [int(item) for item in input().split()]
if abs(x-a) > abs(x-b):
    print("B")
else:
    print("A")