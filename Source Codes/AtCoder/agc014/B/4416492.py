n, m = map(int, input().split())
count = [0] * n
for i in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    count[a] += 1
    count[b] += 1

for i in count:
    if i % 2 == 1:
        print("NO")
        exit()

print("YES")