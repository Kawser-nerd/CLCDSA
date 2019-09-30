a, b, c = map(int, input().split())
s=0
for i in range(1, b+1):
    if (a * i) % b == c:
        s = 1
        break
print("YES" if s else "NO")