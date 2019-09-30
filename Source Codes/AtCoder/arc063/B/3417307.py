N, T = map(int, input().split())
A = list(map(int, input().split()))

min_a = A[0]
profit = 0
ans = 0
for a in A[1:]:
    min_a = min(min_a, a)
    if a - min_a > profit:
        profit = a - min_a
        ans = 1
    elif a - min_a == profit:
        ans += 1
print(ans)