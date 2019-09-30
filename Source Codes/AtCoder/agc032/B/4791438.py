n = int(input())

if n % 2 == 0:
    m = 0
    ans = []
    for i in range(1, n+1):
        for j in range(i+1, n+1):
            if j != n - i + 1:
                m += 1
                ans.append((i, j))
else:
    m = 0
    ans = []
    for i in range(1, n+1):
        for j in range(i+1, n+1):
            if j != n - i:
                m += 1
                ans.append((i, j))

print(m)
for (a, b) in ans:
    print(a, b)