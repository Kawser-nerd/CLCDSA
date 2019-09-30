X = int(input())
ans = 1
for b in range(1, X):
    for p in range(2, X):
        x = b**p
        if x <= X:
            ans = max(ans, x)
        else:
            break
print(ans)