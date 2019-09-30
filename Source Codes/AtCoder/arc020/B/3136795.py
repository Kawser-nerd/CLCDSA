n, c = map(int, input().split())
a = [int(input()) for _ in range(n)]
ans = 10**9
for i in range(1, 11):
    for j in range(1, 11):
        if i == j:
            continue
        temp = 0
        for k in range(n):
            if k % 2 == 0:
                if i != a[k]:
                    temp += c
            else:
                if j != a[k]:
                    temp += c
        ans = min(ans, temp)
print(ans)