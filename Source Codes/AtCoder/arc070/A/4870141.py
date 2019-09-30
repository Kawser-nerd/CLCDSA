X = int(input())

l = 0
for i in range(X):
    l += (i + 1)
    if l >= X:
        ans = i + 1
        break

print(ans)