x1, y1, r = map(int, input().split())
x2, y2, x3, y3 = map(int, input().split())

# Red
if (x2 <= (x1-r) and x3 >= (x1+r) and y2 <= (y1-r) and y3 >= (y1+r)):
    print("NO")
else:
    print("YES")

# Blue
r1 = ((x1-x2)**2 + (y1-y2)**2)
r2 = ((x1-x3)**2 + (y1-y3)**2)
r3 = ((x1-x2)**2 + (y1-y3)**2)
r4 = ((x1-x3)**2 + (y1-y2)**2)
if (r1 > r**2 or r2 > r**2 or r3 > r**2 or r4 > r**2):
    print("YES")
else:
    print("NO")