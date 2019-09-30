l = [0 for _ in range(1000002)]
for _ in range(int(input())):
    a, b = map(int, input().split())
    l[a] += 1
    l[b + 1] -= 1
for i in range(len(l)):
    if i > 0: l[i] += l[i - 1]
m = 0
for i in range(len(l)):
    if m < l[i]: m = l[i]
print(m)