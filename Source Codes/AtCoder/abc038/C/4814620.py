# ???

N = int(input())
lst_a = list(map(int, input().split()))
ans = 1
left = 1

for right in range(1, N):
    if lst_a[right-1] < lst_a[right]:
        left += 1
    else:
        left = 1
    ans += left

print(ans)