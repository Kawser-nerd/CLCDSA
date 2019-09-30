a, b, c, d = map(int, input().split())
l = a + b
r = c + d
if l > r:
    print("Left")
elif l == r:
    print("Balanced")
else:
    print("Right")