a = input().rstrip()
b = input().rstrip()

if a == b[::-1]:
    print("YES")
else:
    print("NO")