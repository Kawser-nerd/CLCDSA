n, c, k = map(int, input().split())
s = [int(input()) for _ in range(n)]
s = sorted(s)
num = 0
i = s[0]
m = s[0] + k
p = 1
for j in s[1:]:
    if j <= m and p < c:
        p += 1
    else:
        p = 1
        num += 1
        m = j + k
    i = j
num += 1
print(num)