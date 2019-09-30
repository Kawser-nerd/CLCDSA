N = int(input())
inputs = [int(i) for i in input().split()]

ans = 1
right = 0
used = [False] * (10 ** 5 + 1)
for left in range(N):
    while right < N and not used[inputs[right]]:
        used[inputs[right]] = True
        right += 1
    ans = max(ans, right - left)
    used[inputs[left]] = False

print(ans)