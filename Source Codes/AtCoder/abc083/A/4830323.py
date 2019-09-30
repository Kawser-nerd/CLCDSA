a, b, c, d = [int(item) for item in input().split()]
if a + b > c + d:
    print("Left")
elif a + b < c + d:
    print("Right")
else:
    print("Balanced")