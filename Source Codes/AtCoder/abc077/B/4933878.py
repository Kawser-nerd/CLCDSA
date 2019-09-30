N = int(input())
ans = 0
i = 0
while i * i <= N:
    ans = i * i
    i += 1
print(ans)