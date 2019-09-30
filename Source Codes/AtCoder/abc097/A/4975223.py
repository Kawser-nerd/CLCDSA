a, b, c, d = map(int, input().split())
diff = max(abs(a-b), abs(b-c))
if diff <= d or abs(a-c) <= d:
    print("Yes")
else:
    print("No")