N, T = map(int, input().split())
A = list(map(int, input().split()))
min_A = 1000000001
max_diff = 0
ans = 0
for i in A:
    min_A = min(min_A, i)
    if i - min_A == max_diff:
        ans += 1
    if i - min_A > max_diff:
        max_diff = i - min_A
        ans = 1
print(ans)