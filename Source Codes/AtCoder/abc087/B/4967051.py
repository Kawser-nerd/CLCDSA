a, b, c, x = map(int, [input() for i in range(4)])
ans = 0
for i in range(a+1):
    for j in range(b+1):
        for k in range(c+1):
            if i * 500 + j * 100 + k * 50 == x:
                ans += 1
print(ans)