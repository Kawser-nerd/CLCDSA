n = int(input())
a = list(map(int, input().split()))

x = 0
y = sum(a)
ans = []

for i in range(n-1):
    x += a[i]
    y -= a[i]
    ans.append(abs(x-y))

print(min(ans))