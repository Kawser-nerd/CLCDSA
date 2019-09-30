a, b, c = map(int, input().split())
for i in range(100):
    if (a * i % b == c):
        print("YES")
        exit()
print("NO")