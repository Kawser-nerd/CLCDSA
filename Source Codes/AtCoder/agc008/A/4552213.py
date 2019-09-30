a, b = map(int, input().split())
ans = float('inf')
for i in [1, -1]:
    for j in [1, -1]:
        if b * i >= a * j:
            tmp = b * i - a * j
            if i == -1:
                tmp += 1
            if j == -1:
                tmp += 1
            ans = min(ans, tmp)

print(ans)