N = int(input())
p = list(map(int, input().split()))
ans = 0
i = 0
while i < N:
    if p[i] == i + 1:
        ans += 1
        if i < N - 1 and p[i + 1] == i + 2:
            i += 1
    i += 1
print(ans)