a, b = map(int, input().split())
c, d = map(int, input().split())
if (a == c or a == d or b == c or b == d):
    print("YES")
else:
    print("NO")