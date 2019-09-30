N = int(input())
K = int(input())
i = 0
ans = 1
while i < N:
    ans = min(ans * 2, ans + K)
    i += 1
print(ans)