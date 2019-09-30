N = int(input())
a = list(map(int, input().split()))
a_sort = sorted(a, reverse=True)
ans = 0
for i in range(N):
    if i % 2 == 0:
        ans += a_sort[i]
    else:
        ans -= a_sort[i]

print(ans)