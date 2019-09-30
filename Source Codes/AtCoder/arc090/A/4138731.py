n = int(input())
a1 = list(map(int, input().split()))
a2 = list(map(int, input().split()))
ans = 0
for i in range(n):
    ans = max(ans, sum(a1[:i + 1]) + sum(a2[i:]))
print(ans)