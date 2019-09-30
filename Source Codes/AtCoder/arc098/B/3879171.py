N = int(input())
A = list(map(int, input().split()))
ans = right = total = 0
for left in range(N):
    while right < N and total ^ A[right] == total + A[right]:
        total += A[right]
        right += 1
    ans += right - left
    if left == right:
        right += 1
    else:
        total -= A[left]
print(ans)