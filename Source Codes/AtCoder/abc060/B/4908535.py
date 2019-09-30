a, b, c = map(int, input().split())
a = a % b
t = a
ans = "NO"
for i in range(b):
    t += a
    if (t % b == c):
        ans = "YES"
print(ans)