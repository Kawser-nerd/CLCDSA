X = int(input())
r = int(X ** 0.5)
ans = 0
for i in range(1, r + 1):
    a = 0
    for j in range(1, 11):
        if i ** j <= X:
            a = i ** j
        else:
            break
    ans = max(ans, a)
print(ans)