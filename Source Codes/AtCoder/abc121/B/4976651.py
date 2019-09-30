n, m, c = map(int, input().split())
a = []
b = list(map(int, input().split()))

for i in range(n):
    a.append(list(map(int, input().split())))

count = 0
for i in range(n):
    x = 0
    for j in range(m):
        x += a[i][j] * b[j]
    x += c

    if x > 0:
        count += 1
            
print(count)