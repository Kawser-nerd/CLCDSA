n = int(input())
tar = 2025 - n
ans = []
for i in range(1, 10):
    for j in range(1, 10):
        if i * j == tar:
            ans.append([i, j])
for a in ans:
    print(a[0], 'x', a[1])